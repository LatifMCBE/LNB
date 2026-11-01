# LNB
A Programming Language

1. Download .zip file
2. Download Termux from Fdroid
3. open Termux
4. pkg install file
5. pkg install clang
6. paste:
cd /storage/emulated/0/<path>/main/
clang++ main.cpp -o LNB
mkdir -p ~/bin && cp './LNB' ~/bin/ && chmod +x ~/bin/LMB#+ && grep -qxF 'export PATH="$HOME/bin:$PATH"' ~/.bashrc || echo 'export PATH="$HOME/bin:$PATH"' >> ~/.bashrc; source ~/.bashrc

for compiling:
LNB <file_name>.LNB
