import os
import re
import subprocess
from pathlib import Path
from typing import List


def find_clang_format():
    path_var = os.environ.get("PATH")
    paths = [Path(p) for p in path_var.split(':')]
    results: List[Path] = []
    for path in paths:
        direct = path / 'clang-format'
        if direct.exists():
            results.append(direct)
        glob_res = path.glob("clang-format-*")
        for res in glob_res:
            results.append(res)
        pass
    results = [f for f in results if re.search(r'.*/clang-format(-\d+|)$', str(f))]

    if results:
        return str(results[0])
    else:
        return None


def clang_format():
    clang_format_exec = str('{{cookiecutter.clang_format_executable}}')
    # clang_format_exec = 'auto'

    if clang_format_exec == 'none':
        print('Skipping formatting code ...')
        return
    elif clang_format_exec == 'auto':
        clang_format_exec = find_clang_format()
        if clang_format_exec is None:
            print('ERROR: Unable to auto detect "clang-format" tool')
            return
    else:
        supplied_path = Path(clang_format_exec)
        if not supplied_path.exists():
            print(f'ERROR: clang_format executable "{clang_format_exec}" does not exists')
            return

    with subprocess.Popen([clang_format_exec, '--style', '{{cookiecutter.clang_format_style}}', '--dump-config'], stdout=subprocess.PIPE) as p:
        try:
            p.wait(timeout=5.0)
            res = p.stdout.read().decode('utf-8')
            with open('.clang-format', 'w') as f:
                f.write(res)
            pass
        except:  # Including KeyboardInterrupt, wait handled that.
            p.kill()
            # We don't call p.wait() again as p.__exit__ does that for us.
            raise

    cwd = Path(os.getcwd())

    src = cwd / "src"
    all_files = list(src.rglob("*.cpp")) + list(src.rglob("*.hpp"))
    all_files.sort()

    for file in all_files:
        cmd = [clang_format_exec, '-i', str(file)]
        # print(f'{cwd}$: {" ".join(cmd)}')
        subprocess.call(cmd)


def main():
    clang_format()
    subprocess.call(('git', 'init'))
    subprocess.call(('git', 'add', '.'))
    subprocess.call(('git', 'commit', '-m', 'ROS node generated using cookie template'))
    return

    #

    # subprocess.call(['clang-format-12', '-i', '--style', 'GNU', './src/*.cpp', './src/*.hpp'])


if __name__ == '__main__':
    main()
