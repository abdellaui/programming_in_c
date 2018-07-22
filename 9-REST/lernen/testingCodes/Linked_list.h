#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include <string>
class Linked_list{

		    std::string data;           // String data
		    Linked_list * nexts = NULL;        // Zeiger auf naechste Element

	public:
		Linked_list(std::string);	// Konsturktor
		void set(std::string);		// Setter
		std::string get();			// Getter
		Linked_list * next();				// Zeiger auf naechste Knoten
		Linked_list * insert_at_index(unsigned int, Linked_list *); // Einfuegen am beliebigen Index
		Linked_list * remove_at_index(unsigned int); // Loeschen am beliebigen Index

};


#endif // LINKED_LIST_H_INCLUDED
