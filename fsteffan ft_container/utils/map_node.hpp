#ifndef MAP_NODE_HPP
# define MAP_NODE_HPP

#include "pair.hpp"

template<class KeyType, class ValueType>
class AVLNode {
public:
	AVLNode(ft::pair<KeyType, ValueType>& value) : data_(value), left_(NULL), right_(NULL), parent_(NULL) {}
	~AVLNode() {}

	const ft::pair<KeyType, ValueType>&  GetValue() const { return data_; }
	void      SetLeft(AVLNode* left) { left_ = left; }
	AVLNode*  GetLeft() const { return left_; }
	void      GetRight(AVLNode* right) { right_ = right; }
	AVLNode*  GetRight() const { return right_; }
	void      SetParent(AVLNode* parent) { parent_ = parent; }
	AVLNode*  GetParent() const { return parent_; }

	void      Print() const { std::cout << data_ << std::endl; }

private:
	AVLNode();

	ft::pair<KeyType, ValueType>	data_;
	AVLNode*						left_;
	AVLNode*						right_;
	AVLNode*						parent_;
};

#endif