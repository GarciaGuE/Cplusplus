#ifndef __ED_BTree_HPP__
#define __ED_BTree_HPP__

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <sstream>

/** @brief a BTree's Node.*/
template <class T>
class BTNode{
    public:

        /** @brief Define a shared reference to a BTNode.
         * Manages the storage of a pointer, providing a limited garbage-collection
         * facility, possibly sharing that management with other objects.
         * @see http://www.cplusplus.com/reference/memory/shared_ptr/
         */
        typedef std::shared_ptr< BTNode<T> > Ref;

        /** @name Life cicle.*/
        /** @{*/

        /** @brief Create a BTNode.
         * @post n_children() == 0
         */
        BTNode (T const& it=T(), BTNode<T>::Ref left=nullptr, BTNode<T>::Ref right=nullptr){
            data=it;
            lft=left;
            rgt=right;
        }

        /**
         * @brief Create a BTNode using dynamic memory.
         * @param it the value save in the node.
         * @param left links to the left child.
         * @param right links to the right child.
         * @return a shared referente to the new node.
         */
        static typename BTNode<T>::Ref create(T const& it, BTNode<T>::Ref left=nullptr, BTNode<T>::Ref right=nullptr){
            return std::make_shared<BTNode<T>> (it, left, right);
        }

        /** @brief Destroy a BTNode. **/
        ~BTNode()
        {}

        /** @}*/

        /** @name Observers.*/
        /** @{*/

        /** @brief Get the data item.*/
        const T& item() const{
            return data;
        }

        /** @brief Has it a left child?*/
        bool has_left() const{
            if(lft==nullptr)
                return false;
            else
                return true;
        }

        /** @brief get the left child.*/
        BTNode<T>::Ref left() const{
            return lft;
        }

        /** @brief Has it a right child? */
        bool has_right() const{
            if(rgt==nullptr)
                return false;
            else
                return true;
        }

        /** @brief get the right child.*/
        BTNode<T>::Ref right() const{
            return rgt;
        }
        /** @}*/

        /** @name Modifiers.*/
        /** @{*/

        /** @brief Set the data item.*/
        void set_item(const T& new_it){
            data=new_it;
        }

        /** @brief Set the left child.*/
        void set_left(BTNode<T>::Ref new_child){
            lft=new_child;
        }

        /** @brief Remove link to the left child. */
        void remove_left(){
            //Hint see std::share_ptr doc.
            lft=nullptr;
        }

        /** @brief Set the right child.*/
        void set_right(BTNode<T>::Ref new_child){
            rgt=new_child;
        }

        /** @brief Remove linkt to the right child. */
        void remove_right(){
            //Hint see std::share_ptr doc.
            rgt=nullptr;
        }

    protected:
        //Hint: use typename SNode<T>::Ref for the link to other nodes.
        T data;
        Ref lft, rgt;
};

/**
 * @brief ADT BTree.
 * Models a BTree of T.
 */
template<class T>
class BTree{
    public:

        /** @brief Define a shared reference to a BTNode.
         * Manages the storage of a pointer, providing a limited garbage-collection
         * facility, possibly sharing that management with other objects.
         * @see http://www.cplusplus.com/reference/memory/shared_ptr/
         */
        typedef std::shared_ptr< BTree<T> > Ref;

    /** @name Life cicle.*/
    /** @{*/

        /** @brief Create an empty BTree.
         * @post is_empty()
         */
        BTree (){
            raiz=nullptr;
        }

    /** @brief Create Leaf BTree.
     * @post not is_empty()
     */
    BTree (const T& item){
        raiz=std::make_shared<BTNode<T>> (item, nullptr, nullptr);
    }

    /**
     * @brief Create an empty BTree.
     * @return a shared referente to the new tree.
     */
    static typename BTree<T>::Ref create(){
        return std::make_shared<BTree<T>> ();
    }

    /**
     * @brief Create a leaf BTree.
     * @param item is the root's item.
     * @return a shared referente to the new tree.
     */
    static typename BTree<T>::Ref create(T const& item){
        return std::make_shared<BTree<T>>(item);
    }

    /**
     * @brief Load a tree from a input stream.
     *
     * The input format will be:
     * '[]' for the empty tree.
     * '[ <item> <left-subtree> <right-subtree> ']'
     *
     * For example a tree with three nodes:
     * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
     *
     * @return a reference to the tree created.
     * @warning runtime_error will throw if worng input format was found.
     */
    static typename BTree<T>::Ref create (std::istream& in) noexcept(false){
        auto tree = BTree<T>::create();
        std::string token;
        T data;
        in >> token;
        if(!in)
            throw std::runtime_error("Wrong input format.");

        if (token=="["){
            in>>token;
            std::istringstream my_stream (token);
            my_stream>>data;
            tree->create_root(data);
            tree->set_left(tree->left()->create(in));
            tree->set_right(tree->right()->create(in));
            in>>token;
            if(token!="]")
                throw std::runtime_error("Wrong input format.");
        }
        else if(token!="[]")
            throw std::runtime_error("Wrong input format.");
        return tree;
    }

    /** @brief Destroy a BTree.**/
    ~BTree()
    {}

    /** @}*/

    /** @name Observers*/

    /** @{*/

    /** @brief is the list empty?.*/
    bool is_empty () const{
        if(raiz==nullptr)
            return true;
        else
            return false;
    }

    /** @brief Get the root item.
     * @pre not is_empty();
     */
    T const& item() const{
        assert(!is_empty());
        return raiz->item();
    }

    /**
     * @brief Get the left subtree.
     * @return a reference to the left subtree.
     * @pre !is_empty()
     */
    typename BTree<T>::Ref left() const{
        assert(!is_empty());

        auto lsb = BTree<T>::create();
        lsb->raiz=raiz->left();

        return lsb;
    }

    /**
     * @brief Get the right subtree.
     * @return a reference to the right subtree.
     * @pre !is_empty()   
     */
    typename BTree<T>::Ref right() const{
        assert(!is_empty());

        auto rsb = BTree<T>::create();
        rsb->raiz=raiz->right();

        return rsb;
    }

    /**
     * @brief Fold a binary tree.
     *
     * The output format will be:
     * '[]' for the empty tree.
     * '[ <item> <left-subtree> <right-subtree> ']'
     *
     * For example a tree with three nodes:
     * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
     *
     * @param out is the output stream.
     * @param tree is the tree.
     * @return the output stream.
     * @pre tree!=nullptr
     */
    std::ostream& fold(std::ostream& out) const{
        if(is_empty())
            std::cout<<"[]";
        else{
            std::cout<<"[ "<<item()<<" ";
            left()->fold(out);
            std::cout<<" ";
            right()->fold(out);
            std::cout<<" ]";
        }
        return out;
    }

    /** @}*/

    /** @name Modifiers*/

    /** @{*/

    /**
     * @brief set the roor's item.
     * @pre not is_empty()
     */
    void set_item(const T& new_it){
        assert(!is_empty());
        raiz->set_item(new_it);
    }

    /**
     * @brief Create the root node.
     * item is the new root item.
     * @post !is_empty()
     */
    void create_root(T const& item){
        raiz=std::make_shared<BTNode<T>> (item, nullptr, nullptr);
        assert(!is_empty());
    }

    /**
     * @brief Remove the link to the root node.
     * @post is_empty()
     */
    void remove_root(){
        raiz=nullptr;
        assert(is_empty());
    }

    /**
     * @brief Attach a new subtree as left child of root.
     * @param new_left is the new left subtree.
     * @pre !is_empty()
     */
    void set_left(typename BTree<T>::Ref new_left){
        assert(!is_empty());
        raiz->set_left(new_left->raiz);
    }

    /**
     * @brief Detach the left child of root.
     * @pre !is_empty()
     */
    void remove_left(){
        assert(!is_empty());
        raiz->remove_left();
    }

    /**
     * @brief Attach a new subtree as right child of root.
     * @param t is the new right subtree.
     */
    void set_right(typename BTree<T>::Ref t){
        assert(!is_empty());
        raiz->set_right(t->raiz);
    }

    /**
     * @brief Detach the right child of root.
     * @pre !is_empty()
     */
    void remove_right(){
        assert(!is_empty());
        raiz->remove_right();
    }

    /** @}*/

    protected:

    std::shared_ptr<BTNode<T>> raiz;
};
#endif
