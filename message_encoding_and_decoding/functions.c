#include "functions.h"
#include <string.h>
#include <stdio.h>

char input_stream[255] = "hello world\0";


char encoded_output[255];

int output_buffer[3][3] =
{{0,0,0},
{0,0,0},
{0,0,0}};


int encoding_key[3][3] =
{ { 1,-2, 2},
  {-1, 1, 3},
  { 1,-1,-4} };

int decoding_key[3][3] =
{{-1,-10,-8 },
 {-1, -6,-5 },
 { 0, -1,-1 } };

int identity_martix[3][3] =
{{1,0,0},
 {0,1,0},
 {0,0,1}};


void hello_world()
{
  printf("hello world\n\n\n\n");
}
// to veriy a single char read can be done
void single_char_write()
{
  for(int count = 0 ; count < strlen(input_stream); count++ )
  {
      printf("%c\n",input_stream[count]);
  }
}

// verify the encoder read order
void text_read_encoder()
{
  for(int count = 0; count < 3; count++ )
    {
      for (int dicount = 0 ; dicount < 3; dicount++ )
        {
          printf(" %5i  ", encoding_key[count][dicount]);
        }
        printf("\n" );
    }
}
// verify decoder read order
void read_text_decoder()
{
  for(int count = 0; count < 3; count++ )
    {
      for (int dicount = 0 ; dicount < 3; dicount++ )
        {
          printf(" %5i  ", decoding_key[count][dicount]);
        }
        printf("\n" );
    }
}
// only to be used in a dianosis situation
void key_verification_master()
{
  for(int count = 0; count < 3 ; count++)
    {
      for(int dicount = 0; dicount < 3 ; dicount++)
        {
          for(int tricount = 0; tricount < 3 ; tricount++)
            {
                output_buffer[count][dicount] += encoding_key[count][tricount]*decoding_key[tricount][dicount];
            }
        }

    }

    for(int count = 0; count < 3; count++ )
      {
        for (int dicount = 0 ; dicount < 3; dicount++ )
          {
            printf(" %5i  ", output_buffer[count][dicount]);
          }
          printf("\n"
        );
      }
}
// ment for the user output yes or no
void key_verification_user()
{
  for(int count = 0; count < 3 ; count++)
    {
      for(int dicount = 0; dicount < 3 ; dicount++)
        {
          for(int tricount = 0; tricount < 3 ; tricount++)
            {
                output_buffer[count][dicount] += encoding_key[count][tricount]*decoding_key[tricount][dicount];
            }
        }

    }

    for(int count = 0; count < 3; count++ )
      {
        for (int dicount = 0 ; dicount < 3; dicount++ )
          {
            if(output_buffer[count][dicount] == identity_martix[count][dicount])
            {
              continue;
            }
            else
            {
              printf("this is not the correct key\n");
              break;
            }
          }
      }
}



void text_encoder()
{
    for(int dicount = 0; dicount < 3; dicount++ )
    {
      for (int tricount = 0 ; tricount < 3; tricount++)
      {

      }
    }
}
void text_decoder()
{

}
