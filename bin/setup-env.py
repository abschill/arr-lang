import subprocess
import os

has_build_dir = os.path.exists(os.path.join(os.getcwd(), 'build'))
has_gcc = subprocess.run('gcc -v', shell=True).returncode == 0

if(not has_build_dir):
    os.mkdir('build')

if(not has_gcc):
    print("Installing GCC...")
    print("Return code: ", subprocess.run('apt install gcc', shell=True).returncode)

print('Dependencies Installed')