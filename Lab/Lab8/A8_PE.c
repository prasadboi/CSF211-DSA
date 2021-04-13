#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE -1

ll linear_search(ll arr[], ll count, ll key)
{
    for (ll i = 0; i < count; i++)
    {
        if(arr[i] == key){
            return i;
        }
    }
    
}
void print_Arr(ll arr[], ll count)
{
    for (ll i = 0; i < count; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

void print_postOrder(ll* preorder, ll*  inorder, ll size)
{
    ll root = *(preorder + 0);
    ll loc_root = linear_search(inorder, size, root);    

    //print_Arr(preorder, size);
    //print_Arr(inorder, size);
    
    // print the left half of the tree
    if(loc_root > 0){
        print_postOrder((preorder + 1), (inorder), loc_root);
    }
    // print the right half of the tree
    if(loc_root < size-1)
    {
        print_postOrder((preorder + loc_root + 1), (inorder + loc_root + 1), size - loc_root-1);
    }
    // print the root of the tree
    printf("%lld ", root);
}

int main(int argc, char const *argv[])
{
    ll size = 0;
    scanf("%lld", &size);

    ll preorder[size];
    ll inorder[size];
    for (ll i = 0; i < size; i++)
    {
        scanf("%lld", &inorder[i]);
    }
    for (ll i = 0; i < size; i++)
    {
        scanf("%lld", &preorder[i]);
    }
    
    print_postOrder(preorder, inorder, size);

    return 0;
}
