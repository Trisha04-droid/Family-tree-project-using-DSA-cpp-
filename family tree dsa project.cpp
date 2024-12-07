#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Individual {
private:
    string name;
    string birthdate;
    vector<Individual*> children;

public:
    Individual(string n, string b) : name(n), birthdate(b) {}

    void addChild(Individual* child) 
	{
        children.push_back(child);
    }

    string getName() const 
	{
        return name;
    }

    string getBirthdate() const 
	{
        return birthdate;
    }

    const vector<Individual*>& getChildren() const 
	{
        return children;
    }
};

class FamilyTree {
private:
    Individual* root;

public:
    FamilyTree(string rootName, string rootBirthdate) 
	{	
        root = new Individual(rootName, rootBirthdate);
    }

    void addChild(Individual* parent, Individual* child) 
	{
        parent->addChild(child);
    }

    void visualizeTree(const Individual* node, int depth) const 
	{
        if (node == NULL) 
			return;

        for (int i = 0; i < depth; i++) 
		{
            cout << "  ";  
        }
        cout << node->getName() << " (" << node->getBirthdate() << ")" << endl;

        const vector<Individual*>& children = node->getChildren();
        
		for (size_t i = 0; i < children.size(); ++i) 
		{
            visualizeTree(children[i], depth + 1);
        }
    }

    Individual* getRoot() const 
	{
        return root;
    }
};

int main() {
    FamilyTree family("RS", "01/01/1990");
    vector<Individual*> individuals;

    individuals.push_back(family.getRoot());

    while (true) 
	{
        cout << "\nFamily Tree Generator Menu:" << endl;
        cout << "1. Add Family Member" << endl;
        cout << "2. Visualize Family Tree" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
		{
            string parentName, childName, childBirthdate;

            cout << "Enter parent's name: ";
            cin.ignore();
            getline(cin, parentName);
            cout << "Enter child's name: ";
            getline(cin, childName);
            cout << "Enter child's birthdate: ";
            getline(cin, childBirthdate);

            bool parentFound = false;
            for (size_t i = 0; i < individuals.size(); ++i) 
			{
                if (individuals[i]->getName() == parentName) 
				{
                    Individual* child = new Individual(childName, childBirthdate);
                    family.addChild(individuals[i], child);
                    individuals.push_back(child);
                    parentFound = true;
                    cout << "Family member added successfully." << endl;
                    break;
                }
            }

            if (!parentFound) 
			{
                cout << "Parent not found in the family tree. Please check the name." << endl;
            }
        } 
		else if (choice == 2) 
		{
            cout << "\nFamily Tree Visualization:" << endl;
            family.visualizeTree(family.getRoot(), 0);
        } 
		else if (choice == 3) 
		{
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } 
		else 
		{
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    return 0;
}

