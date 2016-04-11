
class HuffNode {
private:
	HuffNode *left, *right;
	char data; //The letters
	int freq; // The frequency

public:
	HuffNode();
	HuffNode(char, int);
	HuffNode(HuffNode*);
	HuffNode(HuffNode*, HuffNode*);
	
	char getData();   
	int getFreq();
	HuffNode *getLeft();
	HuffNode *getRight();
};

class HuffCompare {
public:
	bool operator()(HuffNode *, HuffNode *);

};