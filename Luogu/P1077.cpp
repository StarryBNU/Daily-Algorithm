#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
//这是
/*
这个问题是因为 VS Code 的配置搜索机制。VS Code 会在当前工作区根目录（即你打开VS Code的文件夹）的 .vscode 子目录中查找配置文件（如 tasks.json 和 launch.json）。如果你在上级目录配置了 .vscode，那么只有在上级目录作为工作区根目录打开时才会被识别。

具体来说：

当你用 VS Code 打开一个文件夹（称为工作区）时，VS Code 会在这个文件夹内查找 .vscode 目录。

如果当前打开的工作区目录中没有 .vscode 目录，那么上级目录中的 .vscode 是不会被自动识别和使用的。
*/
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",a+b);
    system("pause");
    return 0; //systempasue放return 0后面是无用的！！
}