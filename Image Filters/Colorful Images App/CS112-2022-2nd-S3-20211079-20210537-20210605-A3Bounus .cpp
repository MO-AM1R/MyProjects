// FCAI – Programming 1 – 2022 - Assignment 3 .
// Program Name : Image Editor.cpp .
// Program Description : RGB Image Editor .
// Last Modification Date : 23/4/2022 .
// Author1 and ID and Group : Mohamed Amir Mohamed and ID --> 20211079 .
// Author2 and ID and Group : Badr Mohamed Ragab and ID --> 20210605 .
// Author3 and ID and Group : Mohamed Safaa Abd_ElGwad and ID --> 20210537 .
// Teaching Assistant : Yousra .
// Purpose : RGB Image Editor .

# include <iostream>
# include <fstream>
# include <cstring>
# include <string>
# include <cmath>
# include <regex>
# include "bmplib.cpp"

using namespace std ;

unsigned char image_1[SIZE][SIZE][3], image_2[SIZE][SIZE][3], result[SIZE][SIZE][3] ;

int num_image = 0 ;

string file_1 , file_2 ;

ifstream direction, direction_2 ;

void loadImage () ;

void saveImage () ;

void do_something() ;

void merge() ;


// Here I call the functions .

int main()
{
    // Here I call do_something Function .

    loadImage() ;

    do_something() ;

    saveImage() ;

    cout << "\n\nThanks for using Image_Editor :)\n" ;

    return 0 ;

}



//_________________________________________

//Here I load the image from user .

void loadImage ()
{
    char imageFileName[100] ;

    //While true to loop until user input correct images ,and I do the same thing but on one Image .

    while(true)
    {
        cout << "\nEnter the first source image file name \n-->" ;

        cin >> imageFileName ;

        file_1 = strcat (imageFileName, ".bmp") ;

        direction.open(file_1) ;

        if(direction)
        {
            readRGBBMP(imageFileName, image_1) ;

            break ;
        }

        else

            cout << "\nThe file is Not Exist :(\n" << endl ;

    }
}


//_________________________________________

// Here I load the second Image .

void loadImage_2()
{

    char imageFileName_2[100] ;

    cout << "\nEnter the Second source image file name \n-->";

    //I take the first image name from user .

    cin >> imageFileName_2;

    //I add ".bmp" To the Image Name .

    file_2 = strcat(imageFileName_2, ".bmp");

    //I get the direction of the Second image .

    direction_2.open(file_2);

    //While true to loop until user input correct images .

    while (true)
    {

        //Here I check if the First image exist or no .

        if (direction_2)
        {

            //If the two images are Exist ,so I read the pixels of their .

            readRGBBMP(imageFileName_2, image_2);

            //Then I break from the images .

            break;
        }


        else
        {

            //Here if the First Image is not Exist .

            cout << "\nThe Second file is Not Exist :(\n" << endl ;

            //So I ask the user to input again .

            cout << "\nEnter the Second source image file name \n-->";

            cin >> imageFileName_2;

            file_1 = strcat(imageFileName_2, ".bmp");

            direction.open(file_2);
        }
    }
}


//_________________________________________

//Here I save the Image

void saveImage ()
{
    char imageFileName[100] ;

    cout << "\nEnter the target image file name \n-->" ;

    //Here I take the Image name from the user ,and the same things in two Images .

    cin >> imageFileName ;

    strcat (imageFileName, ".bmp") ;

    writeRGBBMP(imageFileName, result) ;


}


//_________________________________________

//Here I save the Image

void saveImage_2 ()
{
    char imageFileName[100] ;

    cout << "\nEnter the target image file name \n-->" ;

    //Here I take the Image name from the user ,and the same things in two Images .

    cin >> imageFileName ;

    strcat (imageFileName, ".bmp") ;

    writeRGBBMP(imageFileName, image_1) ;

    cout << "\n\nThanks for using Image_Editor :)\n" ;

    exit(1) ;
}


//_________________________________________

// This function check if the input is valid or no .

bool is_valid (string& text)
{
    // I used regex format to check if the input like this format or no .

    regex int_format ("[0-9]+") ;

    // I used regex_math to check the input matches to the format or no .

    // If it matches so the function return true if no return false .

    return regex_match (text, int_format) ;

}


//_________________________________________

int extract_denominator(string text)
{
    int ind = text.find('/') ;

    text = text.substr(ind + 1 , -1 ) ;

    int denominator = stoi(text) ;

    return denominator ;
}


//_________________________________________

bool rational_option(string text)
{

    // I used regex format to check if the input like this format or no .

    regex rational_format (R"((1)(\s)(\/)(\s)[1-9]?)") ;

    // I used regex_math to check the input matches to the format or no .

    // If it matches so the function return true if no return false .

    return regex_match (text, rational_format) ;

}


//_________________________________________

bool order_check(string text)
{

    // I used regex format to check if the input like this format or no .

    regex int_format ("[1-4]?[1-4]?[1-4]?[1-4]?") ;

    // I used regex_math to check the input matches to the format or no .

    // If it matches so the function return true if no return false .

    return regex_match (text, int_format) ;

}


//_________________________________________

//Here I declare the average .

long long avg = 0 ;

void black_white()
{
    //Here 3 for to loop in the Image pixel .

    for (int l = 0; l < SIZE; ++l)
    {

        for (int m = 0; m < SIZE ; ++m)
        {

            for (int i = 0; i < 3; ++i)
            {
                //Here I increase avg by image_1 [i][j] to calculate the average .

                avg += image_1[l][m][i];

            }
            //if to check that average is bigger than 381 .
            if (avg > 381)
            {
                for (int c = 0; c < 3; ++c)
                {
                    //If true convert the pixel to the white .
                    result[l][m][c] = 255 ;

                }
            }
                //else if to check that average is smaller than 381.
            else if (avg < 381)
            {
                for (int f = 0; f < 3; ++f)
                {

                    //If true convert the pixel to the black .
                    result[l][m][f] = 0 ;

                }
            }
            //after end the filter assign that average equal to 0
            avg = 0 ;
        }
    }
}


//_________________________________________

// Invert

void invert()
{
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {

            for(int k = 0; k<3; k++)
            {

                result[i][j][k] = 255 - image_1[i][j][k];

            }
        }
    }
}


//_________________________________________

//Here Filter Merge .

void merge()
{
    //Here in two for to loop in the Image pixel .

    for (int i = 0; i < SIZE ; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {

            for (int k = 0; k < 3; ++k)
            {

                //Here I convert the Image to black and white .

                result[i][j][k] = ((image_1[i][j][k] + image_2[i][j][k]) / 2 ) ;

            }

        }
    }
}


//_________________________________________

//Here Filter Merge .

void flip()
{

    string text ;

    //Here i declare integer called check.

    int check ;

    //While true to loop until user input correct images .

    cout << "1 - To Horizontal\n2 - To Vertical\n\nEnter the Number of process which you want\n-->" ;

    while(true)
    {
        //Here user input the check .

        cin.ignore();

        getline(cin, text) ;

        if (is_valid(text))
        {

            check = stoi(text);

            if (check == 2)
            {
                //make 3 for to loop on the pixel of the image.

                for (int i = 0; i <SIZE ; ++i)
                {
                    for (int j = 0; j < SIZE; ++j)
                    {
                        for(int k = 0; k<3;++k)
                        {

                            //I flip the Image Vertical .

                            result[i][j][k] = image_1 [SIZE-i][j-SIZE][k] ;

                        }

                    }
                }

                break ;

            }

                //Here I check if the input equal to 2 or no . //Here if check is 1 .

            else if (check == 1)
            {
                //make 3 for to loop on the pixel of the image.

                for (int i = 0; i <SIZE ; ++i)
                {
                    for (int j = 0; j < SIZE; ++j)
                    {
                        for(int k = 0; k<3;++k)
                        {

                            //I flip the Image Horizontal .

                            result[i][j][k] = image_1 [i][SIZE-j][k] ;
                        }
                    }
                }

                break ;

            }

            else

                cout << "Invalid Input :(\n-->" ;

        }

        else

            cout << "Invalid Input :(\nTry again\n-->";

    }
}


//_________________________________________

//Rotate

void rotate()
{

    string text ;

    int option ;

    cout << "1 - Rotate by 90\n2 - Rotate by 180\n3 - Rotate by 270\n-->" ;

    cin.ignore() ;

    getline(cin, text) ;
        
    while(true)
    {
        
        if(is_valid(text))
        {

            option = stoi(text) ;

            if (option == 1)
            {

                for (int i = 0; i < SIZE; i++)
                {

                    for (int j = 0; j < SIZE; j++)
                    {

                        for(int k = 0; k < 3; k++)
                        {

                            result[j][i][k] = image_1[SIZE - i][SIZE - j][k];

                        }
                    }
                }

                break ;

            }

            else if (option == 2)
            {

                for (int i = 0; i < SIZE; ++i)
                {

                    for (int j = 0; j < SIZE; ++j)
                    {

                        for(int k = 0; k < 3; k++)
                        {

                            result[i][j][k] = image_1[SIZE - i][SIZE - j][k];

                        }
                    }
                }

                break ;

            }

            else if (option == 3)
            {

                for (int i = 0; i < SIZE; i++)
                {

                    for (int j = 0; j < SIZE; j++)
                    {

                        for(int k = 0; k < 3; k++)
                        {

                            result[i][j][k] = image_1[j][i][k];

                        }
                    }
                }

                break ;

            }
            
            else
            {

                cout << "Invalid input :(\nTry again\n-->" ;
                
                cin.sync() ;
                
                cin.clear() ;
                
                getline(cin, text) ;
           
            }
        }

        else
        {

            cout << "Invalid input :(\nTry again\n-->" ;
            
            cin.sync() ;
            
            cin.clear() ;
            
            getline(cin, text) ;
           
        }
    }
}


//_________________________________________

//The Darken and Lighten

void darken_lighten()
{
    int check ;

    string str ;

    cout << "\n1 - To Darken\n2 - To lighten\n\nEnter the Number of process which you want \n-->" ;

    //While true to loop until user input correct images .

    while (true)
    {
        //Here user input the choice which he wants .

        cin >> str ;

        //Here I check if the input correct or no .

        if(is_valid(str))
        {
            //If correct ,so I assign check by stoi(str) .

            check = stoi(str) ;

            //Here if check is 1 .

            if (check == 1)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        for(int k = 0 ; k < 3 ; k++)
                        {

                            result[i][j][k] = (image_1[i][j][k] / 2) ;

                        }
                        //So I Darken the Image by devide the color of pixel by 2 .


                    }
                }

                break ;
            }

                //Here if check is 2 .

            else if (check == 2)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        for(int k = 0 ; k < 3 ; k++)
                        {
                            //Then I get the power 0.8 of the color pixel of image then I add 150 To lighten the Image .

                            result[i][j][k] = int(pow(image_1[i][j][k], 0.8)) + 150 ;
                        }
                    }
                }

                break ;
            }

                //Here if check is incorrect .

            else

                cout << "\nInvalid Input  :(\nTry again \n-->"  ;

        }

            //Here if str is incorrect .

        else

            cout << "\nPlease Enter a number :(\nTry again \n-->" ;
    }
}


//_________________________________________

//Edge

void edge()
{
    //Here 3 for to loop in the Image pixel .

    for (int l = 0; l < SIZE; ++l)
    {

        for (int m = 0; m < SIZE ; ++m)
        {

            for (int n = 0; n < 3; ++n)
            {

                //Here I increase avg by image_1 [i][j] to calculate the average .

                avg += image_1[l][m][n];

            }

            //if to check that average is bigger than 381 .

            if (avg > 381)
            {

                for (int c = 0; c < 3; ++c)
                {

                    //If true convert the pixel to the white .

                    image_1[l][m][c] = 255 ;

                }
            }

                //else if to check that average is smaller than 381.

            else if (avg < 381)
            {

                for (int f = 0; f < 3; ++f)
                {

                    //If true convert the pixel to the black .

                    image_1[l][m][f] = 0 ;

                }
            }

            //after end the filter assign that average equal to 0

            avg = 0 ;
        }
    }

    //Here i make 3 for to loop on the image .

    for(int i = 0 ; i< SIZE ; i++)
    {

        for(int j = 0; j < SIZE; j++)
        {

            for(int k = 0 ; k < 3 ;k++)
            {
                //Check if the difference between the pixel and the next pixel, the one above it, and the one below it is not zero.

                if(image_1[i][j][k] - image_1[i][j+1][k] != 0  || image_1[i][j][k] - image_1[i+1][j][k] != 0 || image_1[i][j][k] - image_1[i-1][j][k] != 0)
                {

                    //if true convert it to the black.

                    result[i][j][k] = 0;

                }

                else
                {

                    // if it false convert it to the white .

                    result[i][j][k] = 255;

                }
            }
        }
    }
}


//_________________________________________

//Enlarge

void find_coordinates2(int choice, int& i, int& repeatedj, int& row, int& colunm)
{
    //this function to take the number of the photo quarter that the user wanted and makes the variables take the start and last of the quarter from row and colunm

    switch(choice)
    {
        case 1:

            i = 0 ;

            repeatedj = 0 ;

            row = SIZE / 2 ;

            colunm = SIZE / 2;

            break;

        case 2:

            i = 0 ;

            repeatedj = SIZE / 2;

            row = SIZE / 2;

            colunm = SIZE;

            break;

        case 3:

            i = SIZE / 2 ;

            repeatedj = 0 ;

            row = SIZE ;

            colunm = SIZE / 2 ;

            break;

        case 4:

            i = SIZE / 2 ;

            repeatedj = SIZE / 2;

            row = SIZE;

            colunm = SIZE;

            break;
    }
}


//this array to store the pixels of the image to exchange quarters between it and the photo
void find_coordinates1(int choice, int k)
{
    int i, j, repeatedj, row, colunm, x, y, repeatedy ;

    find_coordinates2(choice, i, repeatedj, row, colunm) ;

    //this switch to take the number of the quarter of the array that we wanted to fill it by photo pixels and make the variable take the start and last of row and colunm of quarter

    switch(k)
    {
        case 1:

            x = 0 ;

            repeatedy = 0;

            break;

        case 2:

            x = 0 ;

            repeatedy = SIZE / 2 ;

            break;

        case 3:

            x = SIZE / 2 ;

            repeatedy = 0 ;

            break;

        case 4:

            x = SIZE / 2 ;

            repeatedy = SIZE / 2 ;

            break;
    }

    //this for loop to fill the image by pixels in the array again

    for( ;i < row ; i++ ,x++)
    {
        for(j = repeatedj ,y = repeatedy ; j < colunm ; j++, y++)
        {
            for(int M = 0 ; M < 3 ; M++)

                image_1[x][y][M] = result[i][j][M] ;
        }
    }
}


void Enlarge_Image()
{

    int choice, k = 1;

    cout << "what do you want Which quarter to enlarge 1, 2, 3 or 4? " << endl;

    cin >> choice;

    //this for loops to fill the array by the pixels of the image to make second copy of it
    
    for(int i = 0 ; i < SIZE ; i++)
    {
        for(int j = 0 ;j < SIZE ; j++)
        {
            for(int M = 0 ; M < 3 ; M++)

                result[i][j][M] = image_1[i][j][M] ;
        }
    }

    find_coordinates1(choice,k);

    //this for loops to make each pixel of the photo became 4 pixels in the array in its second filling to make the quarter of 64*64 became 256*256
    
    for(int k = 0 ,i = 0 ;i < SIZE ;k++, i+=2)
    {
        for(int z = 0 ,j = 0 ; j < SIZE ; z++, j+=2)
        {
            for(int M = 0 ; M < 3 ; M++)
            {

                result[i][j][M] = image_1[k][z][M];

                result[i][j+1][M] = image_1[k][z][M];

                result[i+1][j][M] = image_1[k][z][M];

                result[i+1][j+1][M] = image_1[k][z][M];

            }

        }
    }
}


//_________________________________________

// Shuffle Filter

void shrink()
{
    for (int i = 0; i < SIZE; i ++)
    {
        for (int j = 0; j < SIZE; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                result[i][j][k] = 255;
            }
        }
    }

    cout << "\nEnter the Number which you want to Shrink the Image by \nFor Example [Enter (1 / 9) or (1 / 7) and So on]\n"
            "Important Note the Nominator must be 1 -->" ;

    string str ;

    cin.ignore();

    getline(cin, str) ;

    while (true)
    {

        if (rational_option(str))
        {
            int denominator = extract_denominator(str) ;

            for (int i = 0; i < SIZE; i += denominator)
            {
                for (int j = 0; j < SIZE; j += denominator)
                {
                    for(int k = 0; k < 3; k ++)
                    {

                        result[i / denominator][j / denominator][k] = image_1[i][j][k];

                    }
                }
            }

            break ;

        }

        else
        {

            cout << "\nPlease Enter a number :(\nTry again \n-->" ;

            getline(cin, str) ;

        }
    }
}


//_________________________________________

void mirror()

{
    while(true)
    {
        //Here i declare an integer called mirror_num .

        int mirror_num;

        cout << "Enter numbers from 1 to 4 for the part that you want to mirror it\n"
                "1 - mirror 1/2 upper -->\n2 - mirror 1/2 lower -->\n3 - mirror 1/2 right -->\n"
                "4 - mirror 1/2 left -->\n-->" ;

        //Here i take input mirror_num .

        cin>>mirror_num;

        if(mirror_num == 1)
        {
            //Here i make 3 for to loop on the half upper of the image .

            for (int i = 0; i <128 ; ++i) {

                for (int j = 0; j < SIZE; j++)

                {
                    for(int k = 0; k < 3; k++)
                    {

                        //Here i put the the half upper of the image in the image call result .

                        result[i][j][k] = image_1[i][j][k];

                    }
                }

                //Here i make for to loop on the  half lower of the image .
                for (int i = 128; i <SIZE ; ++i) {

                    for (int j = 0; j < SIZE; ++j)
                    {
                        for(int k = 0; k < 3; k++)

                        {
                            //I flip the Image Vertical on the  half lower of the image .

                            result [i][j][k] = image_1[SIZE-i][j-SIZE][k];

                        }
                    }
                }
            }

            break;
        }

        //if the mirror_num input is equal to 2 .

        else if (mirror_num == 2)
        {
            //Here i make 3 for to loop on the half  lower of the image .

            for (int i = 128; i <SIZE ; ++i)
            {

                for (int j = 0; j < SIZE; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {

                        //Here i put the the half lower of the image in the image call result .

                        result[i][j][k] = image_1[i][j][k];

                    }
                }
            }

            //Here i make 3 for to loop on the  half upper of the image .

            for (int i = 0; i <128 ; ++i)
            {

                for (int j = 0; j < SIZE; ++j)
                {

                    for (int k = 0; k < 3; k++)
                    {

                        //I flip the Image Vertical on the  half upper of the image .

                        result[i][j][k] = image_1[SIZE - i][j - SIZE][k];

                    }
                }
            }

            break;
        }

        //if the mirror_num input is equal to 3 .

        else if(mirror_num == 3)
        {
            //Here i make 3 for to loop on the left half of the image .

            for (int i = 0; i <SIZE ; ++i)
            {

                for (int j = 0; j < SIZE/2; j++)
                {

                    for(int k = 0; k < 3; k++)
                    {
                        //Here i put the the right half of the image in the image call result .

                        result[i][j][k] = image_1[i][(SIZE-128)+j][k];

                        result[i][j+128][k] = result[i][j][k];

                    }
                }

                //Here i make 3 for to loop on the left half of the image .

                for (int i = 0; i <SIZE ; ++i)
                {

                    for (int j = 0; j < 128; ++j)
                    {

                        for(int k = 0; k < 3; k++)
                        {

                            //I flip the left half of the image  Horizontal .

                            result [i][j][k] = result[i][SIZE-j][k];

                        }
                    }
                }
            }

            break;
        }

        //if the mirror_num input is equal to 4 .

        else if(mirror_num == 4)
        {
            //Here i make 3 for to loop on the left half of the image .

            for (int i = 0; i <SIZE ; ++i)
            {

                for (int j = 0; j < SIZE/2; j++)
                {

                    for(int k = 0; k < 3; k++)
                    {
                        //Here i put the the left half of the image in the image call result

                        result[i][j][k] = image_1[i][(SIZE/2)-j][k];

                        result[i][j+128][k] = result[i][j][k];

                    }
                }

                //Here i make for to loop on the left half of the image .

                for (int i = 0; i <SIZE ; ++i)
                {

                    for (int j = 0; j < SIZE/2; j++)
                    {

                        for(int k = 0; k < 3; k++)
                        {
                            //Here i put the left half of the image in the image call result .

                            result[i][j][k] = image_1[i][j][k];

                        }
                    }
                }
            }

            break;
        }

        else
        {
            //if it false tell the that invalid input and allow to him to enter the input again .

            cout<<"invalid input"<<endl;

        }
    }
}


//_________________________________________

void moveQuarter(int idx, int i, int j)
{
    int temp = j ;

    if (idx == 1)
    {

        for (int k = 0; k < SIZE / 2; i++, k++)
        {

            for (int z = 0, j = temp ; z < SIZE / 2; j++, z++)
            {

                for (int l = 0; l < 3; ++l)
                {

                    result[i][j][l] = image_1[k][z][l] ;

                }
            }
        }
    }

    else if (idx == 2)
    {

        for (int k = 0; k < SIZE / 2; i++, k++)
        {

            for (int z = SIZE / 2, j = temp; z < SIZE; j++, z++)
            {

                for (int l = 0; l < 3; ++l)
                {

                    result[i][j][l] = image_1[k][z][l] ;

                }
            }
        }
    }

    else if (idx == 3)
    {

        for (int k = SIZE / 2 ; k < SIZE; i++, k++)
        {

            for (int z = 0, j = temp; z < SIZE/2; j++, z++)
            {

                for (int l = 0; l < 3; ++l)
                {

                    result[i][j][l] = image_1[k][z][l] ;

                }
            }
        }
    }

    else if (idx == 4)
    {

        for (int k = SIZE / 2; k < SIZE; i++,k++)
        {

            for (int z = SIZE/2, j = temp; z < SIZE; j++,z++)
            {

                for (int l = 0; l < 3; ++l)
                {

                    result[i][j][l] = image_1[k][z][l] ;

                }
            }
        }
    }
}


//_________________________________________

void shuffleImage()
{
    string text = " " ;

    int order_1, order_2, order_3, order_4 ;

    cout<<"\nEnter the order of quarters you want\n-->";

    while(!text.empty())
    {

        cin.clear() ;

        cin.sync() ;

        getline(cin, text) ;

        if(order_check(text) && text.length() == 4)
        {

            order_1 = int (text[0] - 48) ;

            order_2 = int (text[1] - 48) ;

            order_3 = int (text[2] - 48) ;

            order_4 = int (text[3] - 48) ;

            break ;

        }

        else
        {

            cout << "\nInvalid input :(\nTry again\n-->" ;

            text = '\0' ;
        }
    }

    for (int i = 0; i < 4; ++i)
    {

        if (i == 0)

            moveQuarter(order_1, 0, 0);

        else if (i == 1)

            moveQuarter(order_2, 0, SIZE / 2);

        else if (i == 2)

            moveQuarter(order_3, SIZE / 2, 0);

        else if (i == 3)

            moveQuarter(order_4, SIZE / 2, SIZE / 2);

    }
}


//_________________________________________

void blur()
{
    long long avg = 0;

    for (int i = 0; i < 250; ++i)
    {

        for (int j = 0; j < 250; ++j)
        {

            for (int k = 0; k < 3; ++k)
            {


                for (int l = i; l < (i + 7) ; ++l)
                {

                    for (int m = j; m < (j + 7) ; ++m)
                    {

                        avg = avg + image_1[l][m][k] ;

                    }
                }

                result[i][j][k] = (avg / 49) ;

                avg = 0 ;
            }
        }
    }

    for (int k = 250 ; k < SIZE ; k++)
    {

        for (int l = 0 ; l < SIZE ; l++)
        {

            for(int i = 0 ; i < 3 ; i++)
            {

                result[k][l][i] = result[k - 1][l][i] ;

            }
        }
    }

    for (int k = 0 ; k < SIZE ; k++)
    {

        for (int l = 250 ; l < SIZE ; l++)
        {

            for(int i = 0 ; i < 3 ; i++)
            {

                result[k][l][i] = result[k][l - 1][i] ;

            }
        }
    }
}


//_________________________________________

// Do_something .

void do_something()
{

    char str ;

    cout << "\nEnter The Numbers or characters as ...\n\n1 - Black and white\n2 - Invert\n3 - Merge\n4 - Flip\n5 - Rotate"
            "\n6 - Darken and Lighten\n7 - Detect Image Edges\n8 - Enlarge\n9 - Shrink\nA - Mirror 1/2 Image\nB - Shuffle\nC - Blur\n"
            "S - To save the image\n0 - To Exit\n\nPlease Enter The number of process which you want :) \n-->" ;

    //While true to loop until user input correct images .

    while (true)
    {
        //Here user input the choice which he wants .

        cin >> str;

        //Then, I call each Function which the user input ,and after calling the Filters I call saveImage Function .

        if (str == '1')
        {

            black_white();

            break ;

        }

        else if (str == '2')
        {

            invert();

            break ;

        }

        else if (str == '3')
        {

            loadImage_2() ;

            merge();

            break ;

        }

        else if (str == '4')
        {

            flip();

            break ;

        }

        else if (str == '5')
        {

            rotate();

            break ;

        }

        else if (str == '6')
        {

            darken_lighten();

            break ;

        }

        else if (str == '7')
        {

            edge();

            break ;

        }

        else if (str == '8')
        {

            Enlarge_Image() ;

            break ;

        }

        else if (str == '9')
        {

            shrink();

            break ;

        }

        else if (str == 'A')
        {

            mirror();

            break ;

        }

        else if (str == 'B')
        {

            shuffleImage();

            break ;

        }

        else if (str == 'C')
        {

            blur();

            break ;

        }

        else if (str == 'S')
        {

            saveImage_2();

            break ;

        }

        else if (str == '0')
        {

            exit(1) ;

        }

        // Here if check is incorrect .

        else

            cout << "\nInvalid Input :(\nTry again \n-->";

    }

    cout << endl ;
}
