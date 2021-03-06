//by Angel English s3543536
//iterator based off example by Paul Miller
//based off of the linked list example by Paul Miller
#include "custom_tree.h"
/* new typedef */
using bst=binary_search_tree;


bool bst::iterator::operator != (const iterator &it) const {
	return it.curr != curr;
}

bst::node * bst::iterator::operator * () const {
	if(curr != nullptr) {
		return curr->get();
	} else {
		return nullptr;
	}
}

bst::node * bst::iterator::operator -> () const {
	if(curr != nullptr) {
		return curr->get();
	} else {
		return nullptr;
	}
}

//pre
bst::iterator &bst::iterator::operator ++ () {
	if(queue.size() == 0) {
		curr = nullptr;
		return *this;
	}
	curr = queue.front();
	queue.pop_front();

	if(curr->get()->left != nullptr) {
		queue.push_back(&(curr->get()->left));
	}
	if(curr->get()->right != nullptr) {
		queue.push_back(&(curr->get()->right));
	}
	return *this;
}
//post
bst::iterator &bst::iterator::operator ++ (int) {
	curr = queue.front();
	if(queue.size() == 0) {
		curr = nullptr;
		return *this;
	}
	queue.pop_front();

	if(curr->get()->left != nullptr) {
		queue.push_back(&(curr->get()->left));
	}
	if(curr->get()->right != nullptr) {
		queue.push_back(&(curr->get()->right));
	}
	return *this;
}

bst::iterator bst::begin() const {
	return bst::iterator(&(this->head));
}

bst::iterator bst::end() const {
	return bst::iterator(nullptr);
}


/* && means change of ownership */
void bst::node::set_left(std::unique_ptr<bst::node>&& newnext)
{
    left = std::move(newnext);
}

void bst::node::set_right(std::unique_ptr<bst::node>&& newnext)
{
    right = std::move(newnext);
}

int bst::size() const {
	return this_size;
}

bst::node * bst::node::get_left(void) const
{
    return left.get();
}

bst::node * bst::node::get_right(void) const
{
    return right.get();
}

bst::node * bst::node::get_parent(void) const
{
    return parent.get();
}

std::string bst::node::get_data(void) const
{
    return data;
}

std::unique_ptr<bst::node>& bst::node::get_left_ptr(void)
{
    return left;
}

std::unique_ptr<bst::node>& bst::node::get_right_ptr(void)
{
    return right;
}

std::unique_ptr<bst::node>& bst::node::get_parent_ptr(void)
{
    return parent;
}

bool bst::add(std::string data)
{
    node * current;
    node * prev = nullptr;
    std::unique_ptr<bst::node> newnode = std::make_unique<bst::node>(data);
    if(head == nullptr)
    {
        head = std::move(newnode);
        ++this_size;
        return true;
    }
    current = head.get();//get the pointer held by the unique_ptr
    while(current != nullptr)
    {

		if(current->data <= data) {
			if(true || current->left != nullptr) {
				//go left
				prev = current;
				current = current->get_left();
			} else {
				//insert left
				//current->left = std::move(newnode);
				//break;
			}
		} else {
			if(true || current->right != nullptr) {
				//go right
				prev = current;
				current = current->get_right();
			} else {
				//insert right
				//current->right = std::move(newnode);
				//break;
			}
		}
    }
	if(prev->data <= data) {
		prev->left = std::move(newnode);
	} else {
		prev->right = std::move(newnode);
	}
    ++this_size;
    return true;
}


bool bst::search(std::string needle) const {
	node *current;
	if(head == nullptr) {
		return false;
	}
	current = head.get();

	while(current != nullptr && current->get_data() != needle) {
		if(current->get_data() < needle) {
			current = current->get_left();
		} else {
			current = current->get_right();
		}
	}
    return current != nullptr;
}
