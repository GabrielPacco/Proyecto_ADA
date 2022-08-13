#ifndef LOGO_HPP
#define LOGO_HPP

#include <iostream>
#include <clocale>

using namespace std;

void mostrarLogo()
{
    cout << R"(
 ____ __________    _________   _____    _____________________    _________   _______________.____     
|    |   \      \  /   _____/  /  _  \   \__    ___/\______   \  /  _  \   \ /   /\_   _____/|    |    
|    |   /   |   \ \_____  \  /  /_\  \    |    |    |       _/ /  /_\  \   Y   /  |    __)_ |    |    
|    |  /    |    \/        \/    |    \   |    |    |    |   \/    |    \     /   |        \|    |___ 
|______/\____|__  /_______  /\____|__  /   |____|    |____|_  /\____|__  /\___/   /_______  /|_______ \
                \/        \/         \/                     \/         \/                 \/         \/
)"
     << endl;
     cout<<endl<< "Bienvenido a UNSA TRAVEL" <<endl<<endl;
     system("pause");
}

#endif // LOGO_HPP