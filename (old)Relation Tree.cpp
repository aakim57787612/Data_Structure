#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct node {
	int gender;//0為女；1為男；2為雌雄同體;
	int age;//0最小 3最大
	string name;//fig2需要看名子

	node* parent;//父母
	node* child;//小孩
	node* bro;//兄弟
	node* sis;//姊妹
	node* spouse;//婚姻
};
//in-law(姻親)指基於婚姻關係而生之親屬型態
int main()//int argc, char* argv[]
{
	string input; node fig1;
	ifstream ifs("EX1-input.txt", ios::in);

	//ifstream ifs;
	//ifs.open(argv[1]);

	fig1.name = "wife"; fig1.gender = 0; fig1.age = 0;
	node husband; husband.name = "husband"; husband.gender = 1; husband.age = 3;//老公
	node sister; sister.name = "sister"; sister.gender = 0; sister.age = 2;//姊妹
	node brother_in_law; brother_in_law.name = "brother-in-law"; brother_in_law.gender = 1;//姊妹老公
	node brother; brother.name = "brother"; brother.gender = 1; brother.age = 3;//兄弟
	node sister_in_law; sister_in_law.name = "sister-in-law"; sister_in_law.gender = 0;//兄弟老婆
	node nephew; nephew.name = "nephew"; nephew.gender = 1; nephew.age = 0;//兄弟兒子
	node niece; niece.name = "niece"; niece.gender = 0; niece.age = 3;//兄弟女兒
	node father; father.name = "father"; father.gender = 1; //爸爸
	node mother; mother.name = "mother"; mother.gender = 0;  mother.age = 0;//媽媽
	node uncle; uncle.name = "uncle"; uncle.gender = 1; uncle.age = 2;//uncle
	node aunt; aunt.name = "aunt"; aunt.gender = 0; aunt.age = 3;//aunt
	node uncle1; uncle1.name = "uncle"; uncle1.gender = 1;//aunt's uncle
	node cousin; cousin.name = "cousin"; cousin.gender = 1;//aunt's son
	node grandfather; grandfather.name = "grandfather"; grandfather.gender = 1; //grandfather
	node grandmother; grandmother.name = "grandmother"; grandmother.gender = 0; //grandmother
	node greatgrandfather; greatgrandfather.name = "great grandfather"; greatgrandfather.gender = 1; //greatgrandfather
	node greatgrandmother; greatgrandmother.name = "great grandmother"; greatgrandmother.gender = 0; //greatgrandmother
	node daughter; daughter.name = "daughter"; daughter.gender = 0;  daughter.age = 0;//daughter
	node son_in_law; son_in_law.name = "son-in-law"; son_in_law.gender = 1;//son_in_law
	node son; son.name = "son"; son.gender = 1;  son.age = 3;//son
	node daughter_in_law; daughter_in_law.name = "daughter-in-law"; daughter_in_law.gender = 0;//daughter_in_law
	node grandson; grandson.name = "grandson"; grandson.gender = 1; grandson.age = 0; //grandson
	node granddaughter; granddaughter.name = "granddaughter"; granddaughter.gender = 0; granddaughter.age = 3; //granddaughter
	node grandson_in_law; grandson_in_law.name = "grandson-in-law"; grandson_in_law.gender = 1;//grandson_in_law
	node greatgranddaughter; greatgranddaughter.name = "great granddaughter"; greatgranddaughter.gender = 0; //greatgranddaughter
	node father_in_law; father_in_law.name = "father-in-law"; father_in_law.gender = 1;//father_in_law
	node mother_in_law; mother_in_law.name = "mother-in-law"; mother_in_law.gender = 0;//mother_in_law
	node brother_in_law1; brother_in_law1.name = "brother-in-law"; brother_in_law1.age = 0; brother_in_law1.gender = 1;//brother-in-law
	node sister_in_law1; sister_in_law1.name = "sister-in-law"; sister_in_law1.gender = 0; sister_in_law1.age = 2;//sister-in-law

	node none; none.name = "none";//none
	//自己(female)
	fig1.parent = &mother;
	fig1.child = &son;
	fig1.spouse = &husband;
	fig1.bro = &brother;
	fig1.sis = &sister;
	//husband
	husband.parent = &mother_in_law;
	husband.child = &son;
	husband.spouse = &fig1;
	husband.bro = &brother_in_law1;
	husband.sis = &sister_in_law1;
	//sister
	sister.parent = &mother;
	sister.child = &none;
	sister.spouse = &brother_in_law;
	sister.bro = &brother;
	sister.sis = &fig1;
	//brother_in_law
	brother_in_law.parent = &none;
	brother_in_law.child = &none;
	brother_in_law.spouse = &sister;
	brother_in_law.bro = &none;
	brother_in_law.sis = &none;
	//brother
	brother.parent = &mother;
	brother.child = &niece;
	brother.spouse = &sister_in_law;
	brother.bro = &sister;
	brother.sis = &fig1;
	//sister_in_law
	sister_in_law.parent = &none;
	sister_in_law.child = &niece;
	sister_in_law.spouse = &brother;
	sister_in_law.bro = &none;
	sister_in_law.sis = &none;
	//nephew
	nephew.parent = &brother;
	nephew.child = &none;
	nephew.spouse = &none;
	nephew.bro = &none;
	nephew.sis = &niece;
	//niece
	niece.parent = &brother;
	niece.child = &none;
	niece.spouse = &none;
	niece.bro = &nephew;
	niece.sis = &none;
	//father
	father.parent = &none;
	father.child = &fig1;
	father.spouse = &mother;
	father.bro = &none;
	father.sis = &none;
	//mother
	mother.parent = &grandmother;
	mother.child = &fig1;
	mother.spouse = &father;
	mother.bro = &uncle;
	mother.sis = &aunt;
	//uncle
	uncle.parent = &grandmother;
	uncle.child = &none;
	uncle.spouse = &none;
	uncle.bro = &aunt;
	uncle.sis = &mother;
	//aunt
	aunt.parent = &grandmother;
	aunt.child = &cousin;
	aunt.spouse = &uncle1;
	aunt.bro = &uncle;
	aunt.sis = &mother;
	//uncle1
	uncle1.parent = &none;
	uncle1.child = &cousin;
	uncle1.spouse = &aunt;
	uncle1.bro = &none;
	uncle1.sis = &none;
	//cousin
	cousin.parent = &aunt;
	cousin.child = &none;
	cousin.spouse = &none;
	cousin.bro = &none;
	cousin.sis = &none;
	//grandfather
	grandfather.parent = &none;
	grandfather.child = &mother;
	grandfather.spouse = &grandmother;
	grandfather.bro = &none;
	grandfather.sis = &none;
	//grandmother
	grandmother.parent = &greatgrandmother;
	grandmother.child = &mother;
	grandmother.spouse = &grandfather;
	grandmother.bro = &none;
	grandmother.sis = &none;
	//greatgrandfather
	greatgrandfather.parent = &none;
	greatgrandfather.child = &grandmother;
	greatgrandfather.spouse = &greatgrandmother;
	greatgrandfather.bro = &none;
	greatgrandfather.sis = &none;
	//greatgrandmother
	greatgrandmother.parent = &none;
	greatgrandmother.child = &grandmother;
	greatgrandmother.spouse = &greatgrandfather;
	greatgrandmother.bro = &none;
	greatgrandmother.sis = &none;
	//daughter
	daughter.parent = &fig1;
	daughter.child = &none;
	daughter.spouse = &son_in_law;
	daughter.bro = &son;
	daughter.sis = &none;
	//son_in_law
	son_in_law.parent = &none;
	son_in_law.child = &none;
	son_in_law.spouse = &daughter;
	son_in_law.bro = &none;
	son_in_law.sis = &none;
	//son
	son.parent = &fig1;
	son.child = &granddaughter;
	son.spouse = &daughter_in_law;
	son.bro = &none;
	son.sis = &daughter;
	//daughter_in_law
	daughter_in_law.parent = &none;
	daughter_in_law.child = &granddaughter;
	daughter_in_law.spouse = &son;
	daughter_in_law.bro = &none;
	daughter_in_law.sis = &none;
	//grandson
	grandson.parent = &son;
	grandson.child = &none;
	grandson.spouse = &none;
	grandson.bro = &none;
	grandson.sis = &granddaughter;
	//granddaughter
	granddaughter.parent = &son;
	granddaughter.child = &greatgranddaughter;
	granddaughter.spouse = &grandson_in_law;
	granddaughter.bro = &grandson;
	granddaughter.sis = &none;
	//grandson_in_law
	grandson_in_law.parent = &none;
	grandson_in_law.child = &greatgranddaughter;
	grandson_in_law.spouse = &granddaughter;
	grandson_in_law.bro = &none;
	grandson_in_law.sis = &none;
	//greatgranddaughter
	greatgranddaughter.parent = &granddaughter;
	greatgranddaughter.child = &none;
	greatgranddaughter.spouse = &none;
	greatgranddaughter.bro = &none;
	greatgranddaughter.sis = &none;
	//father_in_law
	father_in_law.parent = &none;
	father_in_law.child = &husband;
	father_in_law.spouse = &mother_in_law;
	father_in_law.bro = &none;
	father_in_law.sis = &none;
	//mother_in_law
	mother_in_law.parent = &grandmother;
	mother_in_law.child = &husband;
	mother_in_law.spouse = &father_in_law;
	mother_in_law.bro = &none;
	mother_in_law.sis = &none;
	//brother_in_law1
	brother_in_law1.parent = &mother_in_law;
	brother_in_law1.child = &none;
	brother_in_law1.spouse = &none;
	brother_in_law1.bro = &husband;
	brother_in_law1.sis = &sister_in_law1;
	//sister_in_law1
	sister_in_law1.parent = &mother_in_law;
	sister_in_law1.child = &none;
	sister_in_law1.spouse = &none;
	sister_in_law1.bro = &husband;
	sister_in_law1.sis = &brother_in_law1;

	node Frank; Frank.name = "Frank Vanderboom"; Frank.gender = 1;//Frank
	node magical; magical.name = "A magical flower"; magical.gender = 3;//magical
	node Emma; Emma.name = "Emma Vanderboom"; Emma.gender = 0;//Emma
	node Samuel; Samuel.name = "Samuel Vanderboom"; Samuel.gender = 1;//Samuel
	node Ida; Ida.name = "Ida Reiziger"; Ida.gender = 0;//Ida
	node Albert; Albert.name = "Albert Vanderboom"; Albert.gender = 1;//Albert
	node Leonard; Leonard.name = "Leonard Vanderboom"; Leonard.gender = 1;//Leonard
	node Rose; Rose.name = "Rose Vanderboom"; Rose.gender = 0;//Rose
	node Laura; Laura.name = "Laura Vanderboom"; Laura.gender = 0;//Laura
	node Mary; Mary.name = "Mary Vanderboom"; Mary.gender = 0;//Mary
	node James; James.name = "James Vanderboom"; James.gender = 1;//James
	node Unknown; Unknown.name = "Unknown sibling"; Unknown.gender = 3;//Unknown
	node Aldous; Aldous.name = "Aldous Vanderboom"; Aldous.gender = 1;//Aldous
	node William; William.name = "William Vanderboom"; William.gender = 1;//William
	node Vanderboom; Vanderboom.name = "Vanderboom Ancestry"; Vanderboom.gender = 3;//Vanderboom
	//Frank
	Frank.parent = &Emma;
	Frank.child = &none;
	Frank.spouse = &none;
	Frank.bro = &none;
	Frank.sis = &none;
	//magical
	magical.parent = &none;
	magical.child = &Frank;
	magical.spouse = &Emma;
	magical.bro = &none;
	magical.sis = &none;
	//Emma
	Emma.parent = &Mary;
	Emma.child = &Frank;
	Emma.spouse = &magical;
	Emma.bro = &Samuel;
	Emma.sis = &Albert;
	//Samuel
	Samuel.parent = &Mary;
	Samuel.child = &Leonard;
	Samuel.spouse = &Ida;
	Samuel.bro = &Albert;
	Samuel.sis = &Emma;
	//Ida
	Ida.parent = &none;
	Ida.child = &Leonard;
	Ida.spouse = &Albert;
	Ida.bro = &none;
	Ida.sis = &none;
	//Albert
	Albert.parent = &Mary;
	Albert.child = &Rose;
	Albert.spouse = &Ida;
	Albert.bro = &Samuel;
	Albert.sis = &Emma;
	//Leonard
	Leonard.parent = &Samuel;
	Leonard.child = &none;
	Leonard.spouse = &none;
	Leonard.bro = &none;
	Leonard.sis = &Rose;
	//Rose
	Rose.parent = &Albert;
	Rose.child = &Laura;
	Rose.spouse = &none;
	Rose.bro = &Leonard;
	Rose.sis = &none;
	//Laura
	Laura.parent = &Rose;
	Laura.child = &none;
	Laura.spouse = &none;
	Laura.bro = &none;
	Laura.sis = &none;
	//Mary
	Mary.parent = &none;
	Mary.child = &Emma;
	Mary.spouse = &James;
	Mary.bro = &none;
	Mary.sis = &none;
	//James
	James.parent = &Unknown;
	James.child = &Emma;
	James.spouse = &Mary;
	James.bro = &none;
	James.sis = &none;
	//Unknown
	Unknown.parent = &Vanderboom;
	Unknown.child = &James;
	Unknown.spouse = &none;
	Unknown.bro = &Aldous;
	Unknown.sis = &William;
	//Aldous
	Aldous.parent = &Vanderboom;
	Aldous.child = &none;
	Aldous.spouse = &none;
	Aldous.bro = &William;
	Aldous.sis = &Unknown;
	//William
	William.parent = &Vanderboom;
	William.child = &none;
	William.spouse = &none;
	William.bro = &Unknown;
	William.sis = &Aldous;
	//Vanderboom
	Vanderboom.parent = &none;
	Vanderboom.child = &Unknown;
	Vanderboom.spouse = &none;
	Vanderboom.bro = &none;
	Vanderboom.sis = &none;

	while (getline(ifs, input)) {
		if (input.size() < 2) {
			continue;
		}
		else if (input == "You" || input == "You(female)" || input == "You(male)") {
			cout << "You";
			continue;
		}
			
		string temp = ""; int i = 0; node now; string result = ""; char g = ' ';
		while (input[i] != 47) {
			temp += input[i];
			i++;
		}
		if (temp == "You(female)" || temp == "You")
			g = 'g';
		else
			g = 'b';

		if (temp == "You(female)" || temp == "You"||temp=="You(male)") {
			now = fig1;
			while (i != input.size()) {
				i++; char t = ' ';
				temp = "";
				while (input[i] != 47 && i != input.size()) {
					temp += input[i];
					i++;
					if (input[i] == 40) {
						i++;
						t = input[i];
						while (i != input.size() && input[i] != 47)
							i++;
					}
				}
				if (temp == "wife") {
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "husband") {
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "children" || temp == "child" || temp == "kids") {
					now = *now.child;
					result = temp;
				}
				else if (temp == "son") {
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "daughter") {
					now = *now.child;
					if (now.gender == 1)
						now = *now.sis;
					result = now.name;
				}
				else if (temp == "grandchildern") {
					now = *now.child;
					if (now.child->name == "none") {
						now = *now.bro;
					}
					now = *now.child;
					result = temp;
				}
				else if (temp == "nephew") {
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.bro;
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "niece") {
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.bro;
					now = *now.child;
					if (now.gender == 1)
						now = *now.sis;
					result = now.name;
				}
				else if (temp == "sister") {
					now = *now.sis;
					result = now.name;
				}
				else if (temp == "brother") {
					now = *now.bro;
					result = now.name;
				}
				else if (temp == "mother") {
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "father") {
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "grandson") {
					now = *now.child;
					if (now.child->name == "none") {
						now = *now.bro;
					}
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "granddaughter") {
					now = *now.child;
					if (now.child->name == "none") {
						now = *now.bro;
					}
					now = *now.child;
					if (now.gender == 1)
						now = *now.sis;
					result = now.name;
				}
				else if (temp == "grandparent" || temp == "grandparents") {
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					now = *now.parent;
					result = temp;
				}
				else if (temp == "grandfather") {
					now = *now.parent;
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "grandmother") {
					now = *now.parent;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "parents" || temp == "parent") {
					now = *now.parent;
					result = temp;
				}
				else if (temp == "brother-in-law") {
					if (now.sis->name == "none" || now.sis->spouse->name == "none") {
						now = *now.spouse;
						now = *now.bro;
						result = now.name;
					}
					else {
						now = *now.sis;
						now = *now.spouse;
						result = now.name;
					}
				}
				else if (temp == "sister-in-law") {
					if (now.bro->name == "none" || now.bro->spouse->name == "none") {
						now = *now.spouse;
						now = *now.sis;
						result = now.name;
					}
					else {
						now = *now.bro;
						now = *now.spouse;
						result = now.name;
					}
				}
				else if (temp == "uncle") {
					now = *now.parent;
					now = *now.bro;
					result = now.name;
				}
				else if (temp == "aunt") {
					now = *now.parent;
					now = *now.sis;
					result = now.name;
				}
				else if (temp == "sibling" && t != ' ') {
					if (t == 'y' && now.age == 0) {
						if (now.sis->age == 2)
							now = *now.sis;
						else if (now.bro->age == 2)
							now = *now.bro;
					}
					else if (t == 'y' && now.age != 0) {
						if (now.sis->age == 0)
							now = *now.sis;
						else if (now.bro->age == 0)
							now = *now.bro;
					}
					else if (t == 'e' && now.age == 3) {
						if (now.sis->age == 2)
							now = *now.sis;
						else if (now.bro->age == 2)
							now = *now.bro;
					}
					else if (t == 'e' && now.age != 3) {
						if (now.sis->age == 3)
							now = *now.sis;
						else if (now.bro->age == 3)
							now = *now.bro;
					}
					t = ' ';
					result = now.name;
				}
				else if (temp == "sibling" || temp == "siblings") {
					if (now.sis->name != "none")
						now = *now.sis;
					else if (now.bro->name != "none")
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "cousin") {
					now = *now.parent;
					if (now.sis->child->name != "none") {
						now = *now.sis;
						now = *now.child;
					}
					else {
						now = *now.bro;
						now = *now.child;
					}
					result = now.name;
				}
				else if (temp == "mother-in-law") {
					now = *now.spouse;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "father-in-law") {
					now = *now.spouse;
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "great grandparent" || temp == "great grandparents") {
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					result = temp;
				}
				else if (temp == "great grandmother") {
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "great grandfather") {
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				if (t == 'y' || t == 'e') {
					while (t == 'y' && now.age != 0) {
						if (now.sis->age == 0)
							now = *now.sis;
						else if (now.bro->age == 0)
							now = *now.bro;
					}
					while (t == 'e' && now.age != 3) {
						if (now.sis->age == 3)
							now = *now.sis;
						else if (now.bro->age == 3)
							now = *now.bro;
					}
					result = now.name;
				}
			}
			if (result == "wife"&&g=='g')
				result = "You";
			else if (result == "husband" && g == 'b')
				result = "You";
			cout << result << endl;
		}
		else {
			if (temp == "A magical flower")
				now = magical;
			else if (temp == "Emma Vanderboom")
				now = Emma;
			else if (temp == "Frank Vanderboom")
				now = Frank;
			else if (temp == "Samuel Vanderboom")
				now = Samuel;
			else if (temp == "Ida Reiziger")
				now = Ida;
			else if (temp == "Albert Vanderboom")
				now = Albert;
			else if (temp == "Leonard Vanderboom")
				now = Leonard;
			else if (temp == "Rose Vanderboom")
				now = Rose;
			else if (temp == "Laura Vanderboom")
				now = Laura;
			else if (temp == "Mary Vanderboom")
				now = Mary;
			else if (temp == "James Vanderboom")
				now = James;
			else if (temp == "Unknown sibling'")
				now = Unknown;
			else if (temp == "Aldous Vanderboom")
				now = Aldous;
			else if (temp == "William Vanderboom")
				now = William;
			else if (temp == "Vanderboom Ancestry")
				now = Vanderboom;
			while (i != input.size()) {
				i++;
				temp = "";
				while (input[i] != 47 && i != input.size()) {
					temp += input[i];
					i++;
				}
				if (temp == "wife") {
					if (now.gender == 1 || now.spouse->gender == 3)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "husband") {
					if (now.gender == 0 || now.spouse->gender == 3)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "children") {
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "child") {
					now = *now.child;
					result = now.name;
				}
				else if (temp == "son") {
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "daughter") {
					now = *now.child;
					if (now.gender == 1)
						now = *now.sis;
					result = now.name;
				}
				else if (temp == "grandchildern") {
					now = *now.child;
					if (now.child->name == "none") {
						now = *now.bro;
					}
					now = *now.child;
					result = now.name;
				}
				else if (temp == "nephew") {
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.bro;
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "niece") {
					if (now.gender == 1)
						now = *now.spouse;
					now = *now.bro;
					now = *now.child;
					if (now.gender == 1)
						now = *now.sis;
					result = now.name;
				}
				else if (temp == "sister") {
					now = *now.sis;
					result = now.name;
				}
				else if (temp == "brother") {
					now = *now.bro;
					result = now.name;
				}
				else if (temp == "cousin") {
					now = *now.parent;
					now = *now.bro;
					now = *now.child;
					result = now.name;
				}
				else if (temp == "mother") {
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "father") {
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "grandson") {
					now = *now.child;
					if (now.child->name == "none") {
						now = *now.bro;
					}
					now = *now.child;
					if (now.gender == 0)
						now = *now.bro;
					result = now.name;
				}
				else if (temp == "granddaughter") {
					now = *now.child;
					if (now.child->name == "none") {
						now = *now.bro;
					}
					now = *now.child;
					if (now.gender == 1)
						now = *now.sis;
					result = now.name;
				}
				else if (temp == "grandparent") {
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					now = *now.parent;
					result = now.name;
				}
				else if (temp == "grandfather") {
					now = *now.parent;
					now = *now.parent;
					if (now.gender == 0)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "grandmother") {
					now = *now.parent;
					now = *now.parent;
					if (now.gender == 1)
						now = *now.spouse;
					result = now.name;
				}
				else if (temp == "parent") {
					now = *now.parent;
					if (now.gender == 0) {
						now = *now.spouse;
					}
					result = now.name;
				}
				else if (temp == "parents") {
					now = *now.parent;
					if (now.gender == 0) {
						now = *now.spouse;
					}
					result = now.name;
				}
				else if (temp == "brother-in-law" && now.name == "A magical flower") {
					now = *now.spouse;
					now = *now.bro;
					now = *now.bro;
					result = now.name;
				}
				else if (temp == "brother-in-law") {
					now = *now.sis;
					now = *now.spouse;
					result = now.name;
				}
				else if (temp == "sister-in-law" && now.name == "Ida Reiziger") {
					now = *now.spouse;
					now = *now.sis;
					result = now.name;
				}
				else if (temp == "sister-in-law") {
					now = *now.bro;
					now = *now.spouse;
					result = now.name;
				}
				else if (temp == "uncle") {
					now = *now.parent;
					now = *now.bro;
					result = now.name;
				}
				else if (temp == "aunt") {
					now = *now.parent;
					now = *now.sis;
					result = now.name;
				}
				else if (temp == "sibling" || temp == "siblings") {
				if (now.sis->name != "none")
					now = *now.sis;
				else if (now.bro->name != "none")
					now = *now.bro;
				result = now.name;
				}
				else if (temp == "mother-in-law") {
				now = *now.spouse;
				now = *now.parent;
				if (now.gender == 1)
					now = *now.spouse;
				result = now.name;
				}
				else if (temp == "father-in-law") {
				now = *now.spouse;
				now = *now.parent;
				if (now.gender == 0)
					now = *now.spouse;
				result = now.name;
				}
				else if (temp == "great grandparent" || temp == "great grandparents") {
				now = *now.parent;
				now = *now.parent;
				now = *now.parent;
				result = now.name;
				}
				else if (temp == "great grandmother") {
				now = *now.parent;
				now = *now.parent;
				now = *now.parent;
				if (now.gender == 1)
					now = *now.spouse;
				result = now.name;
				}
				else if (temp == "great grandfather") {
				now = *now.parent;
				now = *now.parent;
				now = *now.parent;
				if (now.gender == 0)
					now = *now.spouse;
				result = now.name;
				}
			}
			cout << result << endl;
		}
	}
}

