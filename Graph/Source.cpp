// In The Name Of Allah

#include <iostream>
#include <conio.h>
#include <fstream>
#include "Graph.h"

void printInfo(Graph);
void saveInfo(Graph, string);

int main()
{
	Graph g;
	int c, a, b;
	string s;

	cout << "In The Name Of Allah\n\n\nSimple Graph Program\n\n\nDar in barname maximum tedade ras ha "
		<< max << " mibashad.\n\nBraye ijade graf bayad avvalin ras afzude shavad.\n\n" << endl;

	cout << "Menu____________________________________________________________\n\n"
		<< "1. Afzudane ras\n"
		<< "2. Afzudane yaal\n"
		<< "3. Hazfe ras (hazfe akharin rase afzude shode)\n"
		<< "4. Hazfe yaal\n"
		<< "5. Barrasie vojud masir beyne do rase morede nazar\n"
		<< "6. Zakhireye etelaate graf dar file\n"
		<< "7. Khoruj\n\n"
		<< "Gozineye morede nazar ra vared konid : ";
		cin >> c;
	cout << "\n" << endl;

	while (c != 7)
	{
		switch (c)
		{
		case 1:
			cout << "Afzudane ras______________________________________________________\n\n";
			if (g.NumOfV() >= max)
			{
				cout << "Nemitavan bish az " << max << " ras be graf ezafe kard.\n\n" << endl;
				break;
			}
			g.addV();
			cout << "Rase Shomareye " << g.NumOfV() - 1 << " afzude shod.\n\n" << endl;
			break;

		case 2:
			cout << "Afzudane yaal____________________________________________________\n\n";
			if (g.NumOfV() < 2)
			{
				cout << "Nemitavan yaali be graf afzud, zira tedad ras ha " << g.NumOfV() 
					<< " mibashad.\n\n" << endl;
				break;
			}
			cout << "Lotfan shomareye ras haye marbut be yaal ra vared konid :\n";
			cin >> a;
			cin >> b;
			cout << endl;
			if (a >= g.NumOfV() || b >= g.NumOfV() || a < 0 || b < 0 )
			{
				cout << "Ras haye vared shode mojud nist.\n\n" << endl;
				break;
			}
			if (a == b)
			{
				cout << "Dar grafe sade nemitavan toghe ijad kard.\n\n" << endl;
				break;
			}
			g.addE(a, b);
			cout << "Yaal morede nazar afzoude shode.\n\n" << endl;
			break;
			
		case 3:
			cout << "Hazfe ras________________________________________________________\n\n";
			if (g.NumOfV() <= 0)
			{
				cout << "Hich rasi mojud nist.\n\n" << endl;
				break;
			}
			g.delV();
			cout << "Rase Shomareye " << g.NumOfV() << " hazf shod.\n\n" << endl;
			break;

		case 4:
			cout << "Hazfe yaal_______________________________________________________\n\n";
			if (g.NumOfE() <= 0 || g.NumOfV() <= 1)
			{
				cout << "Yaali mojud nist.\n\n" << endl;
				break;
			}
			cout << "Lotfan shomareye ras haye marbut be yaal ra vared konid :\n";
			cin >> a;
			cin >> b;
			cout << endl;
			if (a >= g.NumOfV() || b >= g.NumOfV() || a < 0 || b < 0)
			{
				cout << "Ras haye vared shode mojud nist.\n\n" << endl;
				break;
			}
			if (!g.getV(a).e[b] || !g.getV(b).e[a])
			{
				cout << "Chenin yaali mojud nist.\n\n" << endl;
				break;
			}
			g.delE(a, b);
			cout << "Yaal morede nazar hazf shode.\n\n" << endl;
			break;

		case 5:
			cout << "Barrasie vojud masir beyne do rase morede nazar__________________\n\n";
			if (g.NumOfV() < 2)
			{
				cout << "Nemitavan Barrasi kard, zira tedad ras ha " << g.NumOfV()
					<< " mibashad.\n\n" << endl;
				break;
			}
			cout << "Lotfan shomareye ras haye morede nazar ra vared konid :\n";
			cin >> a;
			cin >> b;
			if (a >= g.NumOfV() || b >= g.NumOfV() || a < 0 || b < 0 || a == b)
			{
				cout << "\nRas haye vared shode nadorost ast.\n\n" << endl;
				break;
			}
			cout << "Beyne do rase " << a << " va " << b << " masir mojud " 
				<< (g.hasDistance(a, b) ? "ast" : "nist") << ".\n\n" << endl;
			break;

		case 6:
			cout << "Zakhireye etelaate graf dar file__________________________________\n\n";
			cout << "Lotfan adress file ra vared konid:\n"
				<< "Braye mesal : example.txt\n(ke dar poosheye barname zakhire mishavad)\n"
				<< "Ya : D:\\example.txt\n(bedoone fasele)\n\n"
				<< "Adres : ";
			cin >> s;
			cout << endl;
			saveInfo(g, s);
			break;

		default:
			cout << "Gozineye vared shode nadorost ast\n\n" << endl;
			break;
		}

		printInfo(g);

		cout << "Menu____________________________________________________________\n\n"
			<< "1. Afzudane ras\n"
			<< "2. Afzudane yaal\n"
			<< "3. Hazfe ras (hazfe akharin rase afzude shode)\n"
			<< "4. Hazfe yaal\n"
			<< "5. Barrasie vojud masir beyne do rase morede nazar\n"
			<< "6. Zakhireye etelaate graf dar file\n"
			<< "7. Khoruj\n\n"
			<< "Gozineye morede nazar ra vared konid : ";
		cin >> c;
		cout << "\n" << endl;
	}

	cout << "Braye koruj yek dokme ra feshar dahid...";
	while (!_kbhit());
	return EXIT_SUCCESS;
}

void printInfo(Graph g)
{
	cout << "Etelaate Graf__________________________________________________\n" << endl;

	if (g.NumOfV() <= 0)
	{
		cout << "Grafi mojud nist.\n" << endl;
		return;
	}

	cout << "Tedade ras ha : " << g.NumOfV() << endl;
	cout << "Tedade yaal ha : " << g.NumOfE() << endl;
	cout << "Darajeye Graf : " << g.maxDegreeOfGraph() << "\n" << endl;

	cout << "\nRas\tDaraje\t\tMottasel be" << endl;
	for (int i = 0; i < g.NumOfV(); i++)
	{
		cout << g.getV(i).num << "\t" << g.degree(i) << "\t\t";
		for (int j = 0; j < g.NumOfV(); j++)
			if (g.getV(i).e[j])
				cout << g.getV(j).num << ' ';
		cout << endl;
	}
	cout << "\n" << endl;

	cout << "Matrise mojaverat :\n" << endl;
	cout << g.matris() << "\n\n" << endl;

	cout << "Graf hamband " << (g.isConnective() ? "ast.\n" : "nist.\n") << endl;

	if (g.isConnective())
	{
		cout << "Peymayeshe DFS : " << g.DFS() << endl;
		cout << "Peymayeshe BFS : " << g.BFS() << "\n\n" <<endl;
	}

	cout << "Graf daraye dor " << (g.hasLoop() ? "ast.\n" : "nist.\n") << endl;

	if (g.isConnective() && !(g.hasLoop()))
		cout << "in garf yek derakht ast\n" << endl;

	return;
}

void saveInfo(Graph g, string s)
{
	if (g.NumOfV() <= 0)
	{
		cout << "Grafi mojud nist.\n\n" << endl;
		return;
	}

	ofstream output(s);
	if (!output)
	{
		cout << "File morede nazar baz nashod. Ehtemalan adres vared shode nadorost ast.\n\n" << endl;
		return;
	}

	output << "A Simple Graph Information\n\n";

	output << "Number of Vertexes : " << g.NumOfV() << "\n";
	output << "Number of Edges : " << g.NumOfE() << "\n";
	output << "Degree of Graph : " << g.maxDegreeOfGraph() << "\n\n";

	output << "\nVertex\tDegree\t\tConnected to\n";
	for (int i = 0; i < g.NumOfV(); i++)
	{
		output << g.getV(i).num << "\t" << g.degree(i) << "\t\t";
		for (int j = 0; j < g.NumOfV(); j++)
			if (g.getV(i).e[j])
				output << g.getV(j).num << ' ';
		output << "\n";
	}
	output << "\n\n";

	output << "Matris :\n\n";
	output << g.matris() << "\n\n\n";

	output << "Graph " << (g.isConnective() ? "is" : "isn't") << " Connective.\n\n";

	if (g.isConnective())
	{
		output << "DFS Traverse : " << g.DFS() << "\n";
		output << "BFS Traverse : " << g.BFS() << "\n\n\n";
	}

	output << "Graph " << (g.hasLoop() ? "has" : "hasn't") << " Loop\n\n";

	if (g.isConnective() && !(g.hasLoop()))
		output << "This graph is a Tree\n\n";

	cout << "Etelaate graf dar file morede nazar zakhire shod.\n\n" << endl;

	return;
}