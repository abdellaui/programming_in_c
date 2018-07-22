<imp>
Linked_list::Linked_list(string s){
	this->set(s);
	this->nexts = NULL;
}

void Linked_list::set(string s){
	this->data = s;
}

string Linked_list::get(){
	return this->data;
}

Linked_list * Linked_list::next(){
	return this->nexts;
}

Linked_list * Linked_list::insert_at_index(unsigned int i, Linked_list* liste){
	if(liste->next() == NULL){  // Wenn Liste ein Ende hat
		if(i == 0){ // Wenn Start der Liste sich aendert
			liste->nexts = this;
			return liste;
		} else {
			unsigned int x = 1;					// Variable zum Iterieren.
			Linked_list * help = this;
			help->nexts = this->nexts;
			while(x<i && help->next()){       // Solange x kleiner i UND der Naechste hat einen Element
				help = help->nexts;
				x++;
			}

			liste->nexts = help->nexts;
			help->nexts = liste;

			help = NULL; // delete
			return this;
		}
	} else {
		return NULL;
	}

}

Linked_list * Linked_list::remove_at_index(unsigned int i){
			unsigned int x = 0;					// Variable zum Iterieren.
			Linked_list * help = this;
			help->nexts = this->nexts;
			while(x<i && help->next()){       // Solange x kleiner i UND der Naechste hat einen Element
				help = help->nexts;
				x++;
			}
			Linked_list * oneMoreHelp = help; // Hilfsvariable

			help->nexts = oneMoreHelp->nexts; // Next-Zeiger zeigt auf Uebernaechsten

			oneMoreHelp = NULL;  // delete
			if(i == 0){
				return this->nexts;
			}
}
