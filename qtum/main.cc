#include <string.h>
#include <iostream>
#include <map>

#include "hashtool.h"

using namespace std;

typedef void (*FP_CMD)(int, char const **);
map <string, FP_CMD> mapCommand;

void ShowCmds(int argc, char const *argv[])
{
    cout << "********* commands *********" << endl;
    for(map<string, FP_CMD>::iterator iter = mapCommand.begin(); iter != mapCommand.end(); iter++)
        cout << iter->first << endl;
    cout << "********* commands *********" << endl;
}

void RegisterCmd()
{
    mapCommand.insert(make_pair("showhash", &ShowHash));
}

int main(int argc, char const *argv[])
{
    /*init*/
    RegisterCmd();

    if(argc < 2)
	{
		ShowCmds(argc, argv);
		return -1;
	}

    string strcmd = string(argv[1]);

    map<string, FP_CMD>::iterator iterCMD = mapCommand.find(strcmd);

	if(iterCMD != mapCommand.end())
		iterCMD->second(argc, argv);
	else
		cout << "Error: unknown method " << strcmd << endl;

    return 0;
}