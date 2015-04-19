#include "Graph.h"
#include "Routing.h"
#include<cstring>
#include<fstream>
string Binary(int num)
{
	string tmp;
	for(int i=0;i<8;i++)
	{
		tmp=to_string((num&1))+tmp;
		num=num>>1;
	}
	return tmp;
}
string ConvertToBinary(string line)
{

	string res;
	char *tmp=strtok(&line[0],".");
	while(tmp!=NULL)
	{
		res=res+Binary(stoi(tmp));
		tmp=strtok(NULL,".");

	}

	return res;
}
int main(int argc,char *argv[])
{
	vector<string>Iptmp;
	Graph g(argv[1]);
	ifstream inIp;
	string line;
	inIp.open(argv[2]);
	while(getline(inIp,line))
	{
		Iptmp.push_back(ConvertToBinary(line));
	}
	inIp.close();
	g.Ip=Iptmp;
//    cout<<endl<<g.Ip[0]<<endl<<g.Ip[1]<<endl<<g.Ip[2]<<endl;
    //int s=1,d=6;
	routing_table(g,stoi(argv[3]),stoi(argv[4]));

return 0;

}
