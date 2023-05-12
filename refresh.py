import os
import subprocess
import chardet

def create_source_file(path, filename):
    """
    在指定路径下创建新的源文件
    """
    with open(os.path.join(path, filename), 'w') as f:
        pass

def get_executables(path):
    """
    读取指定路径下 CMakeLists.txt 中的所有 add_executable 语句所包含的源文件
    """
    executables = []

    with open(os.path.join(path, 'CMakeLists.txt'), 'rb') as f:
        data = f.read()
        encoding = chardet.detect(data)['encoding']

    with open(os.path.join(path, 'CMakeLists.txt'), 'r', encoding=encoding) as f:
        for line in f:
            if line.startswith('add_executable'):
                file = (line.split()[1]).split(")")[0]
                if file.endswith('.cpp'):
                    executables.append(file)
                elif file.endswith('.c'):
                    executables.append(file)
    return executables

def check_source_files(path, files):
    """
    检查指定路径下是否存在所有指定的源文件，如果不存在则创建
    """
    for file in files:
        if not os.path.exists(os.path.join(path, file)):
            print(f'Creating new source file: <{file}>...')
            create_source_file(path, file)

def run_cmake(path):
    """
    运行 cmake 命令，生成 Makefile
    """
    build_path = os.path.join(path, 'build')
    os.makedirs(build_path, exist_ok=True)
    subprocess.run(['cmake', '..'], cwd=build_path)

if __name__ == '__main__':
    path = '.'  # 指定项目路径
    executables = get_executables(path)
    check_source_files(path, executables)
    run_cmake(path)