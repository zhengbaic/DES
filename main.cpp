#include "helper.h"

int main () {
	//ÊäÈë 
	cout << "input your public text:";
	string clear_text;
	getline(cin, clear_text, '\n');
	cout << "input your key(8):";
	string k;
	getline(cin, k, '\n');
	
	//Éú³ÉkÂÖÃÜÔ¿ 
	bitset<64> key = string_2_bitsets(k.c_str());
	vector<bitset<48>> Kkeys = generate_k_keys(key);
	
	bitset<64> clear_text_bitsets = string_2_bitsets(clear_text.c_str());
	bitset<64> cipher_text = DES(clear_text_bitsets, Kkeys, true);
	cout << "encrypt:";
	print_result(cipher_text);
	
	bitset<64> clear_text_bitsets = DES(cipher_text, Kkeys, false);
	cout << endl << "decrypt:";
	print_result(clear_text_bitsets);
	
	system("pause");
}
