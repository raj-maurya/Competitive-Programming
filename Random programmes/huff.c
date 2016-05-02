#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huff.h"

//Function to count frequencies of letters
void frequency_count(char *Filename, int * frequency)
{
  int ch;
  FILE * fp = fopen(Filename, "r"); 
  for(ch = 0; ch < 127; ch++) 
    {
      frequency[ch] = 0;
    }
  while (1) 
    {
      ch = fgetc(fp);
      if(ch == EOF)
	{
	  break;
	}
      frequency[ch]++; 
    }
  fclose(fp); 
}

//Function to build list from frequencies
Node * List_build(int * frequencies)
{
  Node * ln;
  int j = 0;

  while(frequencies[j] == 0)
    {
      j++;
    }

  printf("Inserting %c : %d\n", j, frequencies[j]);
  ln = List_create(j, frequencies[j]);
  j++;
  int i = 0;
  i = j;

  while(i < 127)
    {
      if (frequencies[i] > 0)
	{
	  printf("Inserting %c : %d\n", i, frequencies[i]);
	  ln = List_insert_ascend(ln, i, frequencies[i]);
	}
      i++;
    }
  return ln;
}

//Function create's list starting with index 0 and with values
Node * List_create(int value, int index)
{
  Node * ln = malloc(sizeof(Node));
  ln -> next = NULL;
  ln -> freq = index;
  ln -> char_val = value;
  return ln;
}

//Function sorts list in ascending order
Node * List_insert_ascend(Node * head, int value, int index)
{
  Node * current;
  Node * temp;
  if (head == NULL || head -> freq >= index)
    {
      current = List_create(value, index);
      current -> next = head;
      return(current);
    }

  else
    {
      current = head;
      while(current -> next != NULL && current -> freq < index)
	{
	  current = current -> next;
	}
      temp = List_create(value, index);
      temp -> next = current -> next;
      current -> next = temp;
    }
  return head;
}

//Function deletes list
void List_destroy(Node * head)
{
  if(head != NULL)
    List_destroy(head -> next);
  free(head);
}

//Function creates individual list nodes to be added to lists
ListNode * ListNode_create(TreeNode * tn)
{
  ListNode * wn = malloc(sizeof(ListNode));
  wn -> next = NULL;
  wn -> tree_ptr = tn;
  return wn;
}

//Function takes created list nodes and inserts them
ListNode * ListNode_insert(ListNode * head, ListNode * wn)
{
  if(head == NULL)
    {
      return wn;
    }
  int weight1 = (head -> tree_ptr) -> weight;
  int weight2 = (wn -> tree_ptr) -> weight;
  if (weight1 > weight2)
    {
      wn -> next = head;
      return wn;
    }
  head -> next = ListNode_insert(head -> next, wn);
  return head;
}

//Function takes frequencies from lists and creates list nodes 
ListNode * ListNode_build(Node * freqList)
{
  ListNode * head = NULL;
  while(freqList != NULL)
    {
      TreeNode * tn = TreeNode_create(freqList -> char_val, freqList -> freq);
      ListNode * wn = ListNode_create(tn);
      head = ListNode_insert(head, wn);
      freqList = freqList -> next;
    }
  return head;
}

//Function destroys tree
void Tree_destroy(TreeNode * node)
{
  if(node == NULL)
    return;
  Tree_destroy(node -> left);
  Tree_destroy(node -> right);
  free(node);
}

//Function creates tree
TreeNode * TreeNode_create(int char_val, int weight_val)
{
  TreeNode * node = malloc(sizeof(TreeNode));
  node -> character = char_val;
  node -> weight = weight_val;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}

//Function takes two tree nodes and merges them, creating a new parent node with the value being the sum of the frequencies of both
TreeNode * Tree_merge(TreeNode * tn1, TreeNode * tn2)
{
  TreeNode * tn = malloc(sizeof(TreeNode));
  tn -> left = tn1;
  tn -> right = tn2;
  tn -> character = 0;
  tn -> weight = (tn1 -> weight) + (tn2 -> weight);
  return tn;
}

//Function prints entire tree
void Tree_print(TreeNode * tn, int level)
{
  if(tn == NULL)
    {
      return;
    }
  TreeNode * lc = tn -> left ; 
  TreeNode * rc = tn -> right ; 

  Tree_print ( lc , level + 1) ;
  Tree_print ( rc , level + 1) ;
  int depth ;
  for ( depth = 0; depth < level ; depth ++)
    {
      printf ("   ") ;
    }
  printf (" freq = %d" , tn -> weight);
  if ((lc == NULL) && (rc == NULL))
    {
      printf (" value = %d , ’%c’" , tn -> character , tn -> character ) ;
    }
  printf ("\n");

}

//Function prints list
void Weight_print(ListNode * head)
{
  if(head == NULL)
    {
      return;
    }
  Tree_print(head -> tree_ptr, 0);
  Weight_print(head -> next);
}

//function helps in creating and calculating tree height
int Tree_heightHelper(TreeNode * tn, int height)
{
  if (tn == 0)
    return height;
  int left_h = Tree_heightHelper(tn -> left, height + 1);
  int right_h = Tree_heightHelper(tn -> right, height + 1);
  if (left_h < right_h)
    return right_h;
  if (left_h > right_h)
    return left_h;
  return left_h;
}

//Function calculates tree height
int Tree_height(TreeNode * tn)
{
  return Tree_heightHelper(tn, 0);
}

void Tree_leafHelper(TreeNode * tn, int * num)
{
  if (tn == 0)
    return;
  TreeNode * lc = tn -> left;
  TreeNode * rc = tn -> right;
  if((lc == NULL) && (rc == NULL))
    {
      (*num)++;
      return;
    }
  Tree_leafHelper(lc, num);
  Tree_leafHelper(rc, num);
}

int Tree_leaf(TreeNode * tn)
{
  int num = 0;
  Tree_leafHelper(tn, &num);
  return num;
}


//Function helps to build code book from tree
void buildCodeBookHelper(TreeNode * tn, int ** codebook, int * row, int col)
{
  if (tn == NULL)
    return;
  TreeNode * lc = tn -> left;
  TreeNode * rc = tn -> right;
  if((lc == NULL) && (rc == NULL))
    {
      codebook[*row][0] = tn -> character;
      (*row)++;
      return;
    }
  if(lc != NULL)
    {
      int numRow = Tree_leaf(lc);
      int ind;
      for(ind = * row; ind < (*row) + numRow; ind++)
	{
	  codebook[ind][col] = 0;
	}
      buildCodeBookHelper(lc, codebook, row, col + 1);
    }
  if(rc != NULL)
    {
      int numRow = Tree_leaf(rc);
      int ind;
      for(ind = *row; ind < (*row) + numRow; ind++)
	{
	  codebook[ind][col] = 1;
	}
      buildCodeBookHelper(rc, codebook, row, col + 1);
    }
}

//Function builds codebook from tree
void buildCodeBook(TreeNode * root, int ** codebook)
{
  int row = 0;
  buildCodeBookHelper(root, codebook, &row, 1);
}

//Prints code book
void printCodeBook(int ** codebook, int numRow)
{
  int row;
  for(row = 0; row < numRow; row++)
    {
      printf("%c: ", codebook[row][0]);
      int col = 1;
      while (codebook[row][col] != -1)
	{
	  printf("%d ", codebook[row][col]);
	  col++;
	}
      printf("\n");
    }
}

//prints one byte of information
void printByte(unsigned char onebyte)
{
  unsigned char mask = 0x80;
  while(mask > 0)
    {
      printf("%d", (onebyte & mask) == mask);
      mask >>= 1;
    }
  printf("\n");
}

//Function writes one bit
int writeBit(FILE * fptr, unsigned char bit, unsigned char * whichbit, unsigned char * curbyte)
{
  if((*whichbit) == 0)
    *curbyte = 0;
  unsigned char temp = bit << (7 - (*whichbit));
  *curbyte |= temp;
  int value = 0;
  if ((*whichbit) == 7)
    {
      int ret;
      ret = fwrite(curbyte, sizeof(unsigned char), 1, fptr);
      if(ret == 1)
	{
	  value = 1;
	}
      else
	{
	  value = -1;
	}
    }
  *whichbit = ((*whichbit) + 1) % 8;
  return value;
}

//Function converts character values to bits using bit shifting
void char2bits(FILE * outfptr, int ch, unsigned char * whichbit, unsigned char * curbyte)
{
  unsigned char mask = 0x40; 
  while(mask > 0)
    {
      writeBit(outfptr, (ch & mask) == mask, whichbit, curbyte);
      mask >>= 1;
    }
}

//Function helps create tree header to write to compressed file
void Tree_headerHelper(TreeNode * tn, FILE * outfptr, unsigned char * whichbit, unsigned char * curbyte)
{
  if (tn == NULL)
    {
      return;
    }
  TreeNode * lc = tn -> left;
  TreeNode * rc = tn -> right;
  if((lc == NULL) && (rc == NULL))
    {
      writeBit(outfptr, 1, whichbit, curbyte);
      char2bits(outfptr, tn -> character, whichbit, curbyte);
      return;
    }
  Tree_headerHelper(lc, outfptr, whichbit, curbyte);
  Tree_headerHelper(rc, outfptr, whichbit, curbyte);
  writeBit(outfptr, 0, whichbit, curbyte);
}

//Function creates hedaer to write to compressed file, stores tree in header for decompression
void Tree_header(TreeNode * tn, unsigned int numChar, char * Filename)
{
  FILE * outfptr = fopen(Filename, "w");
  if(outfptr == NULL)
    {
      return;
    }
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  Tree_headerHelper(tn, outfptr, &whichbit, &curbyte);
  writeBit(outfptr, 0, &whichbit, &curbyte);
  padZero(outfptr, &whichbit, &curbyte);
  fwrite(&numChar, sizeof(unsigned int), 1, outfptr);
  unsigned char newline = '\n';
  fwrite(&newline, sizeof(unsigned char), 1, outfptr);
  fclose(outfptr);
}

//Function to compress the file itself. 
int compress(char * infile, char * outfile, int ** codebook, int * mapping)
{
  FILE * infptr = fopen(infile, "r");
  if(infptr  == NULL)
    {
      printf("ERROR");
      return(0); 
    }

  FILE * outfptr = fopen(outfile, "a"); 
  if(outfptr == NULL)
    {
      fclose(outfptr);
      printf("ERROR");
      return(0);
    }
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  while(!feof(infptr))
    {
      int onechar = fgetc(infptr);
      if(onechar != EOF)
	{
	  int ind = mapping[onechar];
	  int ind2 = 1;
	  while(codebook[ind][ind2] != -1)
	    {
	      writeBit(outfptr, (codebook[ind][ind2] == 1), &whichbit, &curbyte);
	      ind2++;
	    }
	}
    }
  padZero(outfptr, &whichbit, &curbyte);
  fclose(infptr);
  fclose(outfptr);
  return(0);
}

//Padding
int padZero(FILE * fptr, unsigned char * whichbit, unsigned char * curbyte)
{
  int rtv = 0;
  while((*whichbit) != 0)
    {
      rtv = writeBit(fptr, 0, whichbit, curbyte);
      if(rtv == -1)
	{
	  return -1;
	}
    }
  return rtv;
}

//Running everything and saving it correctly.
int main(int argc, char **argv)
{

  if(argc < 2)
    {
      printf("Error, no input given.\n");
      return(0);
    }

  int freq_array[127];

  char * filename = argv[1];
  int filename_size = strlen(filename);

  frequency_count(filename, freq_array);

  char * outfile = (char *)malloc(filename_size+5 * sizeof(char));

  strcpy(outfile, filename);
  outfile = strcat(outfile, ".huff");

  Node * list;

  list = List_build(freq_array);
  if (list == NULL)
    {
      return(0);
    }

  Node * temp;
  temp = list;
  while(temp != NULL)
    {
      printf("Frequency of %c = %d\n", temp -> char_val, temp -> freq);
      temp = temp -> next;
    }
  ListNode * tree_list;
  tree_list = ListNode_build(list);

  while(tree_list -> next != NULL)
    {
      ListNode * second = tree_list -> next;
      ListNode * third = second -> next;

      TreeNode * tn1 = tree_list -> tree_ptr;
      TreeNode * tn2 = second -> tree_ptr;

      free(tree_list);
      free(second);
      tree_list = third;

      TreeNode * fin = Tree_merge(tn1, tn2);
      ListNode * wn = ListNode_create(fin);

      tree_list = ListNode_insert(tree_list, wn);
    }
  Weight_print(tree_list); 
  List_destroy(list);
  TreeNode * root = tree_list -> tree_ptr; 
  free(tree_list);

  int numRow = Tree_leaf(root);
  int numCol = Tree_height(root);
  numCol++;
  int ** codebook = malloc(sizeof(int*) * numRow);
  int row;
  for(row = 0; row < numRow; row++)
    {
      codebook[row] = malloc(sizeof(int) * numCol);
      int col;
      for(col = 0; col < numCol; col++)
	{
	  codebook[row][col] = -1;
	}
    }
  buildCodeBook(root, codebook);
  printCodeBook(codebook, numRow);

  unsigned int numChar = 0;
  int z;
  for(z = 0; z < 127; z++)
    {
      numChar += freq_array[z];
    }
  printf("numChar: %d\n", numChar);
  int mapping[127];
  int ind;
  for(ind = 0; ind < 127; ind++)
    {
      mapping[ind] = -1;
      int ind2;
      for(ind2 = 0; ind2 < numRow; ind2 ++)
	{
	  if(codebook[ind2][0] == ind)
	    {
	      mapping[ind] = ind2;
	    }
	}
    }
  Tree_header(root, numChar,outfile);
  compress(filename, outfile, codebook, mapping);
  return(0);
}
