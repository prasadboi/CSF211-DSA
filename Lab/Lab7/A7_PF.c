#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

int a,b;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
	int visited;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode=NULL;

	pNode=(struct TrieNode *)malloc(sizeof(struct TrieNode));

	if(pNode)
	{
		int i;
		pNode->isEndOfWord=false;

		for(i=0;i<ALPHABET_SIZE;i++)
		{
			pNode->children[i]=NULL;
			pNode->visited=0;
		}
	}

	return pNode;
}

int insert(struct TrieNode *root,const char *key,char last[],char first[])
{
	int level;
	int length=strlen(key);
	int index;

	struct TrieNode *pCrawl=root;

	for(level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index]=getNode();

		pCrawl=pCrawl->children[index];
	}

	pCrawl->isEndOfWord=true;
	pCrawl->visited++;
	last[a++]=key[level-1];
	first[b++]=key[0];
	
	return pCrawl->visited;
}

void delete(struct TrieNode *root)
{
    int i;
    
    for(i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->children[i])
            delete(root->children[i]);
    }
    
    free(root);
}

void deleteTrie(struct TrieNode **root)
{
    delete(*root);
    *root=NULL;
}

int main()
{
    int t,j,n,flag1,flag2;
    //scanf("%d%*c",&t);
    int arr[t];
    for(j=0;j<1;j++)
    {
        scanf("%d%*c",&n);
        int i;
        char keys[11];
        char last[n],first[n];
        a=0;
        b=0;
        flag1=0;
        flag2=0;
        struct TrieNode *root = getNode();
        for(i=0;i<n;i++)
        {
            scanf("%s",keys);
            if(insert(root,keys,last,first)!=1)
            {
                flag2=i+1;
                break;
            }
        }
        if(flag2!=0)
        {
            arr[j]=flag2%2;
            continue;
        }
        for(i=1;i<n;i++)
        {
            if(first[i]!=last[i-1])
            {
                flag1=i+1;
                break;
            }
        }
        if(flag1!=0)
            arr[j]=flag1%2;
        else
            arr[j]=(n+1)%2;
        deleteTrie(&root);
    }
    for(j=0;j<t-1;j++)
        (arr[j]==0) ? printf("Alice ") : printf("Bob ");
    (arr[j]==0) ? printf("Alice") : printf("Bob");

	return 0;
}


