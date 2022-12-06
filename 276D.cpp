using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long l,r, ans = 0;
    cin >> l >> r;
    for (int i = 60; ~i; --i){
        if (long long b = 1LL << i; (l & b) != (r & b)){
            ans += b*2;
            break;
        }
    }
    cout << max(0LL, ans-1);
}

C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Users\endof\AppData\Local\Programs\Python\Python39;C:\Users\endof\AppData\Local\Programs\Python\Python39\Scripts;C:\Program Files (x86)\Wolfram Research\WolframScript\;C:\Program Files (x86)\Print Conductor;C:\Program Files\Git\cmd;C:\Program Files\Git\mingw64\bin;C:\Program Files\Git\usr\bin;C:\Users\endof\.jdks\openjdk-17\bin;C:\Users\endof\AppData\Roaming\nvm;C:\Program Files\nodejs;C:\MinGW\bin;C:\ProgramData\pbox;C:\Programs\gcc11-64-winlibs\bin;C:\Program Files (x86)\Elm\0.19.1\bin;C:\Users\endof\scoop\shims;C:\Users\endof\AppData\Local\Microsoft\WindowsApps;C:\Users\endof\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\JetBrains\IntelliJ IDEA Community Edition 2021.2.2\bin;C:\Users\endof\Desktop\Programs\nvim-win64\Neovim\bin;C:\Users\endof\AppData\Local\Microsoft\WindowsApps


C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Users\endof\AppData\Local\Programs\Python\Python39;C:\Users\endof\AppData\Local\Programs\Python\Python39\Scripts;C:\Program Files (x86)\Wolfram Research\WolframScript\;C:\Program Files (x86)\Print Conductor;C:\Program Files\Git\cmd;C:\Program Files\Git\mingw64\bin;C:\Program Files\Git\usr\bin;C:\Users\endof\.jdks\openjdk-17\bin;C:\Users\endof\AppData\Roaming\nvm;C:\Program Files\nodejs;C:\MinGW\bin;C:\ProgramData\pbox;C:\Programs\gcc11-64-winlibs\bin;C:\Users\endof\Desktop\Programs\bin;C:\Program Files (x86)\Elm\0.19.1\bin;C:\Users\endof\scoop\shims;C:\Users\endof\AppData\Local\Microsoft\WindowsApps;C:\Program Files (x86)\Print Conductor;C:\Users\endof\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\JetBrains\IntelliJ IDEA Community Edition 2021.2.2\bin;C:\Users\endof\Desktop\Programs\nvim-win64\Neovim\bin;C:\MinGW\bin;C:\Users\endof\AppData\Roaming\nvm;C:\Program Files\nodejs;C:\Users\endof\AppData\Local\Microsoft\WindowsApps;
