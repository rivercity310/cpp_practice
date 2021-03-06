#include <iostream>
#include <string>
using std::string;

class Product {
	int id, price;
	string intro, manufacturer;
protected:
	Product(int id, int price, string intro, string manufacturer) {
		this->id = id;
		this->price = price;
		this->intro = intro;
		this->manufacturer = manufacturer;
		std::cout << "Product 积己磊 角青" << std::endl;
	}
	string getIntro() { return this->intro; }
	string getManu() { return this->manufacturer; }
	int getPrice() { return this->price; }
	int getID() { return this->id; }
public:
	virtual void show() = 0;
};

class Book : public Product {
	int ISBN;
	string author, title;
public:
	Book(int id, int price, string intro, string manufacturer, string author, string title, int ISBN) : Product(id, price, intro, manufacturer) {
		this->author = author;
		this->title = title;
		this->ISBN = ISBN;
		std::cout << "Book 积己磊 角青" << std::endl;
	}
	void show() override;
};

void Book::show() {
	std::cout << "--- 惑前ID : " << getID() << "\n";
	std::cout << "惑前 汲疙: " << getIntro() << "\n";
	std::cout << "积魂磊: " << getManu() << "\n";
	std::cout << "啊拜: " << getPrice() << "\n";
	std::cout << "历磊: " << author << "\n";
	std::cout << "氓力格: " << title << "\n";
	std::cout << "ISBN: " << ISBN << std::endl;
}

class ConversationBook : public Book {
	string lang;
public:
	ConversationBook(int id, int price, string intro, string manufacturer, string author, string title, int ISBN, string lang) : Book(id, price, intro, manufacturer, author, title, ISBN) {
		this->lang = lang;
		std::cout << "ConversationBook 积己磊 角青" << std::endl;
	}

	void show() override;
};

void ConversationBook::show() {
	Book::show();
	std::cout << "攫绢: " << lang << std::endl;
}

class CompactDisc : public Product {
	string albumTitle, singer;
public:
	CompactDisc(int id, int price, string intro, string manufacturer, string albumTitle, string singer) : Product(id, price, intro, manufacturer) {
		this->albumTitle = albumTitle;
		this->singer = singer;
		std::cout << "CompactDisc 积己磊 角青" << std::endl;
	}
	void show() override;
};

void CompactDisc::show() {
	std::cout << "--- 惑前ID : " << getID() << "\n";
	std::cout << "惑前 汲疙: " << getIntro() << "\n";
	std::cout << "积魂磊: " << getManu() << "\n";
	std::cout << "啊拜: " << getPrice() << "\n";
	std::cout << "举裹 力格: " << albumTitle << "\n";
	std::cout << "啊荐: " << singer << std::endl;
}

void chap8_openchallenge() {
	string intro, manufacturer, author, title, lang, albumTitle, singer;
	int price, ISBN;
	int id = 0;

	Product* products[100];

	std::cout << "**** 惑前 包府 橇肺弊伐阑 累悼钦聪促 ****" << std::endl;
	while (true) {
		std::cout << "惑前 眠啊(1), 葛电 惑前 炼雀(2), 场郴扁(3) : ";
		int select; std::cin >> select;

		switch (select) {
		case 1:
		{
			std::cout << "伙前 辆幅 >> 氓(1), 澜厩 CD(2), 雀拳氓(3): ";
			int kinds; std::cin >> kinds;
			std::cin.ignore();

			switch (kinds) {
			case 1:
			{
				// (int id, int price, string intro, string manufacturer, string author, string title, int ISBN)
				std::cout << "惑前 汲疙: "; std::getline(std::cin, intro);
				std::cout << "积魂磊: "; std::getline(std::cin, manufacturer);
				std::cout << "啊拜: "; std::cin >> price; std::cin.ignore();
				std::cout << "氓 力格: "; std::getline(std::cin, title); 
				std::cout << "历磊: "; std::getline(std::cin, author);
				std::cout << "ISBN: "; std::cin >> ISBN;

				Book* book = new Book(id, price, intro, manufacturer, author, title, ISBN);
				products[id++] = book;
				break;
			}
			case 2:
			{
				//(int id, int price, string intro, string manufacturer, string albumTitle, string singer)
				std::cout << "惑前 汲疙: "; std::getline(std::cin, intro);
				std::cout << "积魂磊: "; std::getline(std::cin, manufacturer);
				std::cout << "啊拜: "; std::cin >> price; std::cin.ignore();
				std::cout << "举裹 力格: "; std::getline(std::cin, albumTitle);
				std::cout << "啊荐: "; std::getline(std::cin, singer);

				CompactDisc* CD = new CompactDisc(id, price, intro, manufacturer, albumTitle, singer);
				products[id++] = CD;
				break;
			}
			case 3:
			{
				//int id, int price, string intro, string manufacturer, string author, string title, int ISBN, string lang)
				std::cout << "惑前 汲疙: "; std::getline(std::cin, intro);
				std::cout << "积魂磊: "; std::getline(std::cin, manufacturer);
				std::cout << "啊拜: "; std::cin >> price; std::cin.ignore();
				std::cout << "氓 力格: "; std::getline(std::cin, title);
				std::cout << "历磊: "; std::getline(std::cin, author);
				std::cout << "ISBN: "; std::cin >> ISBN; std::cin.ignore();
				std::cout << "攫绢: "; std::getline(std::cin, lang);

				ConversationBook* CB = new ConversationBook(id, price, intro, manufacturer, author, title, ISBN, lang);
				products[id++] = CB;
				break;
			}
			default:
				std::cout << "肋给等 急琶涝聪促.." << std::endl;
				break;
			}


			break;
		}
		case 2:
			for (int i = 0; i < id; i++) products[i]->show();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "橇肺弊伐阑 辆丰钦聪促... " << std::endl;
			return;
		default:
			std::cout << "肋给等 急琶涝聪促..." << std::endl;
			break;
		}
	}
}