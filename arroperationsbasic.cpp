#include<iostream>
using namespace std;

class Array {
public:
    int *arr, *arr1,*arr2,*arr3;
    int n;
    int maxSize,maxSize1,maxSize2,maxSize3;

    void ar() {
        cout<<"Create Array"<<endl;
        cout<<"Enter the size of the array: "<<endl;
        cin>>maxSize;
        arr=new int[maxSize];
        
        for(int i=0;i<maxSize;i++) {
            arr[i] = 0;
        }
        cout << "Enter how many values you want to insert in the array: " << endl;
        cin >> n;
        if (n > maxSize) {
            cout << "Number of elements exceeds the maximum size.";
            return;
        }
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < n; i++) {

            cin >> arr[i];

		}

        cout << "Array after creation " << endl;
        traverse();
        cout << endl;
    }

    void insert() {
        int value, p;
        if (n >= maxSize) {
            cout << "Array is full. Cannot insert." << endl;
            return;
        }
        cout << "Enter the element to insert: ";
        cin >> value;
        cout << "Enter the position: ";
        cin >> p;

        if (p < 0 || p > maxSize) {
            cout << "Invalid position!" << endl;
            return;
        }

        for (int i = n; i > p; i--) {
            arr[i] = arr[i - 1];
        }
        arr[p] = value;
        n++;

        cout << "Array after insertion " << endl;
        traverse();
        cout << endl;
    }

    void deletion() {
        int p;
        cout << "Enter the position of the element to delete: ";
        cin >> p;
		if (n == 0) {
            cout << "Array is empty. Cannot delete.\n";
            return;
        }

        if (p < 0 || p >= maxSize) {
            cout << "Invalid position!\n";
            return;
        }

        for (int i = p; i < maxSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[maxSize - 1] = 0; 
        n--;
        
        cout << "Array after deletion " << endl;
        traverse();
        cout << endl;
    }

	void arrlinearsearch(){
			int i=0,e,ifFound;
        	cout<<"Enter the number to search: ";
        	cin>>e;
        	do{
        		if(arr[i]==e){
        		cout<<"ELement is found at Position "<<i+1<<endl;
				ifFound=1;
			}
			    i++;
		}while(i<=maxSize);
			
			if(ifFound==0){
				cout<<endl<<"Element not found";
			}
	}
	
	void arrbinarysearch(){
		int start,middle,end,ub,lb,ele,i,found;
		lb=0;
		ub=maxSize;
		start=lb;
		end=ub;
		cout<<"Enter the number to search: ";
       	cin>>ele;
		while(start<end)
		{
			middle=int(start+end)/2;
			
			if(arr[middle]==ele){
				cout<<"Element found at postion "<<middle<<endl;
				found=1;
				break;
			}
			cout<<"middle"<<middle<<" start "<<start<<" end "<<end<<endl;
			if(arr[middle]<ele)
			{
				start=middle+1;
			}
			else{
				end=middle-1;
			}
			
		}
	if(found==0){
	cout<<"Element not in array";}
	}
	
void bubblesort() {
    int i, p, temp;
    for (p = 0; p < n - 1; p++) { // passes
        for (i = 0; i < n - p - 1; i++) { // no of elements
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    traverse();
}


void merging() {
    int c, n, m;
    int maxSize1, maxSize2;
    int *arr1, *arr2, *arr3;

    cout << "First array:\n";
    cout << "Enter the size of the array 1: " << endl;
    cin >> maxSize1;
    arr1 = new int[maxSize1];

    cout << "Enter how many values you want to insert in the array 1: " << endl;
    cin >> n;
    if (n > maxSize1) {
        cout << "Number of elements exceeds the maximum size.";
        return;
    }
    cout << "Enter the elements of the array 1:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Second array:\n";
    cout << "Enter the size of the array 2: " << endl;
    cin >> maxSize2;
    arr2 = new int[maxSize2];

    cout << "Enter how many values you want to insert in the array 2: " << endl;
    cin >> m;
    if (m > maxSize2) {
        cout << "Number of elements exceeds the maximum size.";
        return;
    }
    cout << "Enter the elements of the array 2:\n";
    for (int b = 0; b < m; b++) {
        cin >> arr2[b];
    }
   
    arr3 = new int[n + m];

    do {
        cout << "\nChoose array type:\n";
        cout << "1. Sorted\n";
        cout << "2. Unsorted\n";
        cout << "3. Exit \n";
        cin >> c;
        int i=0,j=0,k=0;
        switch(c){
            case 1: {
                while(i<n&&j<m){
                    if(arr1[i]<arr2[j]) {
                        arr3[k++] = arr1[i++];
                    } else {
                        arr3[k++] = arr2[j++];
                    }
                }
                while (i < n) {
                    arr3[k++] = arr1[i++];
                }
                while (j < m) {
                    arr3[k++] = arr2[j++];
                }

                cout << "Sorted Array Merged: ";
                for (int x = 0; x < k; x++) {
                    cout << arr3[x] << " ";
                }
                cout << "End" << endl;
                break;
            }
            case 2:
            	int f,h,x;
               for(f=0;f<n;f++) {
                    arr3[f]=arr1[f]; 
                }
                for(h=0;h<m;h++) {
                    arr3[n+h]=arr2[h];
                }

                cout << "Unsorted Array Merged: ";
                for (x=0;x<n+m;x++) { 
                    cout<<arr3[x]<<" ";
                }
                break;
            case 3:
                cout << "Leaving the merging function" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (c != 3);
}
		
void traverse() {
        cout << "Array: ";
        for (int i = 0; i < maxSize; i++) {
            cout << arr[i] << " ";
        }
        cout << "End" << endl;
    }

    void choices() {
        int choice;
        ar();
        do {
            cout << "\nChoose an operation:\n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Traverse\n";
            cout << "4. Linear Search\n";
            cout << "5. Binary Search\n";
            cout << "6. Bubble Sort\n";
            cout << "7.Merge Arrays\n";
            cout << "8. Exit\n";
            cin >> choice;

            switch (choice) {
                case 1:
                    insert();
                    break;
                case 2:
                    deletion();
                    break;
                case 3:
                    traverse();
                    break;
                case 4:
                	arrlinearsearch();
                    break;
                case 5:
                	arrbinarysearch();
                    break;
                case 6:
                	bubblesort();
                    break;
                case 7:
                	merging();
                    break;
                case 8:
                    cout << "Exiting" << endl;
                    break;  
                default:
                    cout << "Invalid choice" << endl;
            }
        } while (choice != 8);
    }
};

int main() {
    Array ob;
    ob.choices();
    return 0;
}



