#include "LogStream.h"

int main(){
    LogStream ls("test5.log");
    ls.NextLine();
    ls.close();
}