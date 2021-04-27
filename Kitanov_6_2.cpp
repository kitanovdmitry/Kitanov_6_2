#include <iostream>

using namespace std;

struct our_struct
{
    int int_field;
    our_struct *p_struct; 
};

void get_value_int_field(int index_of_element,
                         our_struct *start_elem_address)
{
    our_struct *var, *var1;
    var = start_elem_address;

    for(int i = 1; i < index_of_element; i++)
    {
        var1 = var -> p_struct;
        var = var1;
    }

    cout << "The value of this element is " << var -> int_field <<"\n";
}

void get_address_int_field(int index_of_element,
                           our_struct *start_elem_address,
                           our_struct *address)
{
    our_struct *var, *var1;
    var = start_elem_address;

    for(int i = 1; i < index_of_element; i++)
    {
        var1 = var -> p_struct;
        var = var1;
    }

    address = var;
    cout << "The address of this element is " << var -> p_struct <<"\n";
}

int main()
{
    our_struct *start_elem_address, *support_p1, *support_p2;
    start_elem_address = new our_struct; 
    support_p1 = start_elem_address;

    cout << "Enter the number of elements of the structure:\n";
    int number_of_elements = 0;
    cin >> number_of_elements;

    for (int i = 1; i < number_of_elements; i++)
    {
        cout << "Enter the value of the " << i << " element of the integer field:\n";
        cin >> support_p1 -> int_field; 

        support_p2 = new our_struct; 
        support_p1 -> p_struct = support_p2; 
        support_p1 = support_p2;
    }

    cout << "Enter the value of last element of the integer field:\n";
    cin >> support_p1 -> int_field;
    support_p1 -> p_struct = start_elem_address; //последний элемент ссылается на начальный

    our_struct *address;
    support_p1 = start_elem_address;
    int index = 0;
    
    for(int i = 1; i < number_of_elements; i++) /*перемещение по элементам структуры и ссылка на значение последующих элементов?*/
    {
        switch (i)
        {
            case 1:
                index = i+1;
                get_address_int_field(index, start_elem_address, address);
                support_p1 -> p_struct = address;
                index = i+1;
                get_address_int_field(index, start_elem_address, address);
                support_p1 -> p_struct = address;

        }
    }

    int index_of_element = 0;

    do 
    {
        cout << "Enter the value for index of an element of the structure or enter zero for exit from this program:\n";
        cin >> index_of_element;
        if (!index_of_element)
        {
            for (int i = 1; i <= number_of_elements; i++)
            {
                support_p1 = support_p2 -> p_struct;
                delete support_p2;
                support_p2 = support_p1;
            }

            return 0;
        }
    get_value_int_field(index_of_element, start_elem_address);
    }
    while(true);
}
