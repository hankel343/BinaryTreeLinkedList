#ifndef ITEMTYPE_H
#define ITEMTYPE_H
typedef int type;

enum RelationType
{
	LESS,
	GREATER,
	EQUAL
};

class ItemType {
public:
	ItemType();
	RelationType ComparedTo(ItemType inputItem);
	void Set(type inputItem) { item = inputItem; };
	type Get() { return item; };
private:
	type item;
};

#endif ITEMTYPE_H