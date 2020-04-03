/* \author Aaron Brown */
// Quiz on implementing kd tree

#include "../../render/render.h"


// Structure to represent node of kd tree
struct Node
{
	std::vector<float> point;
	int id;
	Node* left;
	Node* right;

	Node(std::vector<float> arr, int setId)
	:	point(arr), id(setId), left(NULL), right(NULL)
	{}
};

struct KdTree
{
	Node* root;

	KdTree()
	: root(NULL)
	{}

	void insertHelp(Node **node, std::vector<float> point, int id, int depth)
	{
		if(*node == NULL)
			*node = new Node(point,id);
		
		else
		{
			int cd = depth % 2 ;
			if (point[cd] > (*node)->point[cd])
				insertHelp(&((*node)->right),point,id,depth+1);
			else
				insertHelp(&((*node)->left),point,id,depth+1);

		}
	}
	void insert(std::vector<float> point, int id)
	{
		// TODO: Fill in this function to insert a new point into the tree
		// the function should create a new node and place correctly with in the root 

		insertHelp(&root,point,id,0);
	}

	void searchHelper(std::vector<float> target, float distanceTol,Node* node,int depth, std::vector<int>& ids)
	{
		float distance;
		if(node!=NULL)
		{

			if( (node->point[0]>=(target[0]-distanceTol)&&node->point[0]<=target[0]+distanceTol) && (node->point[1]>=(target[1]-distanceTol)&&node->point[1]<=(target[1]+distanceTol)))
				{
					distance = sqrt(pow(target[0]-node->point[0],2)+pow(target[1]-node->point[1],2));
					if (distance <= distanceTol)
						ids.push_back(node->id);
				
				}
				
			
			if ((target[depth%2] - distanceTol) < node->point[depth%2]  )
				searchHelper(target,distanceTol, node->left, depth+1, ids);
			if ((target[depth%2] + distanceTol) > node->point[depth%2] )
				searchHelper(target,distanceTol, node->right, depth+1, ids);
		}
			
	}
	// return a list of point ids in the tree that are within distance of target
	std::vector<int> search(std::vector<float> target, float distanceTol)
	{

		std::vector<int> ids;
		searchHelper(target,distanceTol, root, 0, ids);
		return ids;

	}
	

};




