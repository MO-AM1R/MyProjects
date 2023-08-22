// FCAI – Programming 1 – 2022 - Assignment 3 .
// Program Name : Image Editor.cpp .
// Program Description : Image Editor .
// Last Modification Date : 23/4/2022 .
// Author1 and ID and Group : Mohamed Amir Mohamed and ID --> 20211079 .
// Author2 and ID and Group : Badr Mohamed Ragab and ID --> 20210605 .
// Author3 and ID and Group : Mohamed Safaa Abd_ElGwad and ID --> 20210537 .
// Teaching Assistant : Yousra .
// Purpose : Image Editor .

# include <iostream>
# include <fstream>
# include <cstring>
# include <cmath>
# include <regex>
# include "bmplib.cpp"

using namespace std ;

unsigned char image_1[SIZE][SIZE], image_2[SIZE][SIZE], result[SIZE][SIZE] ;

int num_image = 0 ;

string file_1 , file_2 ;

ifstream direction, direction_2 ;

void loadImage () ;

void saveImage () ;

void do_something() ;


// Here I call the functions .

int main()
{

    cout << "\nHello User :)\n\nWelcome to Image Editor :)\n" << endl;

    // Here I call do_something Function .

    loadImage() ;

    // Here I call do_something Function .

    do_something() ;

    // Here I call SaveImage Function .

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
            readGSBMP(imageFileName, image_1) ;

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

            readGSBMP(imageFileName_2, image_2);

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

//Here I save the Result

void saveImage ()
{
    char imageFileName[100] ;

    cout << "Enter the target image file name \n-->" ;

    //Here I take the Image name from the user ,and the same things in two Images .

    cin >> imageFileName ;

    strcat (imageFileName, ".bmp") ;

    writeGSBMP(imageFileName, result) ;

}


//_________________________________________

//Here I save the Image_1

void saveImage_2 ()
{
    char imageFileName[100] ;

    cout << "\nEnter the target image file name \n-->" ;

    //Here I take the Image name from the user ,and the same things in two Images .

    cin >> imageFileName ;

    strcat (imageFileName, ".bmp") ;

    writeGSBMP(imageFileName, image_1) ;

    cout << "\n\nThanks for using Image_Editor :)\n" ;

    exit(1) ;

}


//_________________________________________

// This function check if the input is valid or no .

bool is_valid(string text)
{
    // I used regex format to check if the input like this format or no .

    regex int_format ("[0-9]?[A-B-C-S]?") ;

    // I used regex_math to check the input matches to the format or no .

    // If it matches so the function return true if no return false .

    return regex_match (text, int_format) ;

}


//_________________________________________

int extract_denominator(string text)
{
    int ind = text.find('/') ;

    text = text.substr(ind + 1, -1) ;

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

// Black and White Filter
void black_white()
{
    //Here I declare the average .

    long avg ;

    //Here in two for to loop in the Image pixel .

    for (int i = 0; i <SIZE ; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //Here I increase avd by image_1 [i][j] to calculate the average .

            avg += image_1 [i][j];
        }
    }

    //Here I devide avd by the Number of pixels to calculate the average .

    avg = avg / (SIZE * SIZE) ;

    for (int i = 0; i <SIZE ; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //Here I convert the Image to black and white .

            if( image_1[i][j] > avg )

                result[i][j] = 255;

            else

                result[i][j] = 0 ;
        }
    }

    cout << endl ;
}


//_________________________________________

// Invert Filter

void invert()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //Here I invert the Images by subtract 255 from the color of pixel .

            result[i][j] = 255 - image_1[i][j] ;

        }
    }

    cout << endl ;
}


//_________________________________________

// Merge Filter .

void merge()
{
    //Here in two for to loop in the Image pixel .

    for (int i = 0; i < SIZE ; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {

            //Here I convert the Image to black and white .

            result[i][j] = ((image_1[i][j] + image_2[i][j]) / 2 ) ;

        }
    }
}


//_________________________________________

// Flip Filter .

void flip()
{
    int check ;

    string str ;

    cout << "\n1 - To Horizontal\n2 - To Vertical\n\nEnter the Number of process which you want \n-->" ;

    //While true to loop until user input correct images .

    while (true)
    {
        //Here user input the choice which he wants .

        cin >> str ;

        //Here I check if the input correct or no .

        if (is_valid(str))
        {
            //If correct ,so I assign check by stoi(str) .

            check = stoi(str) ;

            //Here if check is 2 .

            if (check == 2)
            {
                for (int i = 0; i <SIZE ; ++i)
                {
                    for (int j = 0; j < SIZE; ++j)
                    {

                        //I flip the Image Vertical .

                        result[i][j] = image_1[SIZE - i][j - SIZE] ;

                    }
                }

                break ;
            }

                //Here if check is 1 .

            else if (check == 1)
            {

                for (int i = 0; i <SIZE ; ++i)
                {

                    for (int j = 0; j < SIZE; ++j)
                    {

                        //I flip the Image Horizontal .

                        result[i][j] = image_1[i][SIZE-j] ;

                    }

                }

                break ;
            }

                //Here if check is incorrect .

            else

                cout << "Invalid Input :(\nTry again \n-->" ;

        }

            //Here if str is incorrect .

        else

            cout << "Please Enter a number :(\nTry again \n-->" ;

    }

    cout << endl ;
}


//_________________________________________

// Rotate Filter

void rotate()
{
    string str ;

    int option ;

    cout << "1 - Rotate by 90\n2 - Rotate by 180\n3 - Rotate by 270\n\n-->" ;

    //While true to loop until user input correct images .

    while (true)
    {
        //Here user input the choice which he wants .

        cin >> str ;

        //Here if check is 1 .

        if(is_valid(str))
        {
            //If correct ,so I assign check by stoi(str) .

            option = stoi(str) ;

            //Here if option is 1 .

            if (option == 1)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        //SO I Rotate by 90 .

                        result[j][i] = image_1[SIZE - i][SIZE - j];

                    }
                }

                break ;
            }

                //Here if option is 2 .

            else if (option == 2)
            {

                for (int i = 0; i < SIZE; ++i)
                {
                    for (int j = 0; j < SIZE; ++j)
                    {

                        //SO I Rotate by 180 .

                        result[i][j] = image_1[SIZE - i][SIZE - j];

                    }
                }

                break ;
            }

                //Here if option is 3 .

            else if (option == 3)
            {

                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {

                        //SO I Rotate by 270 .

                        result[i][j] = image_1[j][i];

                    }
                }

                break ;
            }

                //Here if option is incorrect .

            else

                cout << "Invalid Input :(\nTry again \n-->";
        }

            //Here if str is incorrect .

        else

            cout << "Please Enter a number :(\nTry again \n-->" ;

    }

    cout << endl ;
}


//_________________________________________

// Darken and Lighten Filter .

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

                        result[i][j] = (image_1[i][j] / 2) ;

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

                        //Then I get the power 0.8 of the color pixel of image then I add 150 To lighten the Image .

                        result[i][j] = int(pow(image_1[i][j], 0.8)) + 150 ;

                    }
                }

                break ;
            }

                //Here if check is incorrect .

            else

                cout << "Invalid Input  :(\nTry again \n-->"  ;

        }

            //Here if str is incorrect .

        else

            cout << "Please Enter a number :(\nTry again \n-->" ;
    }
}


//_________________________________________

// Edge Filter .

void edge()
{
    //Here I declare the average .

    long avg;

    //Here two for to loop in the Image pixel .

    for (int i = 0; i <SIZE ; ++i)
    {

        for (int j = 0; j < SIZE; ++j)
        {
            //Here I increase avd by image_1 [i][j] to calculate the average .

            avg += image_1 [i][j];


        }
    }

    //Here I devide avd by the Number of pixels to calculate the average .

    avg = avg / (SIZE * SIZE);

    for (int i = 0; i <SIZE ; ++i)
    {

        for (int j = 0; j < SIZE; ++j)
        {

            //Here I convert the Image to black and white .

            if(image_1[i][j] > avg)

                image_1[i][j] = 255;

            else

                image_1[i][j] = 0;

        }
    }

    //Here I make a for to loop on the image .

    for(int i = 0 ; i< SIZE ; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //Check if the difference between the pixel and the next pixel, the one above it, and the one below it is not zero.

            if(image_1[i][j]- image_1[i][j+1] != 0  || image_1[i][j] - image_1[i+1][j] != 0
            || image_1[i][j] - image_1[i-1][j] != 0)
            {

                //if true convert it to the black.

                result[i][j] = 0;

            }

            else
            {

                // if it false converts it to the black .

                result[i][j] = 255 ;

            }
        }
    }
}


//_________________________________________

// Enlarge Filter .

void find_coordinates2(int choice, int& i, int& repeatedj, int& row, int& colunm)
{
    //this function to take the number of the photo quarter that the user wanted and makes the variables take the start

    // and last of the quarter from row and colunm .

    switch(choice)
    {
        case 1 :

            i = 0 ;

            repeatedj = 0 ;

            row = SIZE / 2 ;

            colunm = SIZE / 2 ;

            break;

        case 2 :

            i = 0 ;

            repeatedj = SIZE / 2 ;

            row = SIZE / 2 ;

            colunm = SIZE ;

            break;

        case 3 :

            i = SIZE / 2 ;

            repeatedj = 0 ;

            row = SIZE ;

            colunm = SIZE / 2 ;

            break;

        case 4 :

            i = SIZE / 2 ;

            repeatedj = SIZE / 2 ;

            row = SIZE ;

            colunm = SIZE ;

            break;

    }
}


//this array to store the pixels of the image to exchange quarters between it and the photo .

void find_coordinates1(int choice, int k)
{
    int i, j, repeatedj, row, colunm, x, y, repeatedy ;

    find_coordinates2(choice, i, repeatedj, row, colunm) ;

    //this switch to take the number of the quarter of the array that we wanted to fill it by photo pixels

    // and make the variable take the start and last of row and colunm of quarter .

    switch(k)
    {
        case 1 :

            x = 0 ;

            repeatedy = 0 ;

            break;

        case 2 :

            x = 0 ;

            repeatedy = SIZE / 2 ;

            break;

        case 3 :

            x = SIZE / 2 ;

            repeatedy = 0 ;

            break;

        case 4 :

            x = SIZE / 2 ;

            repeatedy = SIZE / 2 ;

            break;
    }

    //this for loop to fill the image by pixels in the array again .

    for(; i < row ; i++, x++)
    {

        for(j = repeatedj, y = repeatedy ; j < colunm ; j++, y++)
        {

            image_1[x][y]=result[i][j];

        }
    }
}


void Enlarge_Image()
{

    int choice, k = 1 ;

    cout << "What do you want Which quarter to enlarge 1, 2, 3 or 4?\n-->" << endl ;

    cin >> choice;

    //this for loops to fill the array by the pixels of the image to make second copy of it .

    for(int i = 0; i < SIZE; i++)
    {

        for(int j = 0 ;j < SIZE; j++)
        {

            result[i][j] = image_1[i][j] ;

        }
    }

    find_coordinates1(choice, k) ;

    //this for loops to make each pixel of the photo became 4 pixels in the array in its

    // second filling to make the quarter of 64*64 became 256 * 256 .

    for(int k = 0, i = 0; i < SIZE; k++, i += 2)
    {

        for(int z = 0, j = 0; j < SIZE ; z++, j += 2)
        {

            result[i][j] = image_1[k][z];

            result[i][j + 1] = image_1[k][z];

            result[i + 1][j] = image_1[k][z];

            result[i + 1][j + 1] = image_1[k][z];

        }
    }

    //to translate all pixels of the array to the image again .

    for(int i = 0;i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {

            image_1[i][j] = result[i][j] ;

        }
    }
}


//_________________________________________

// Shrink Filter

void shrink()
{
    // First I should make the background white .

    // So I loop in every rwo in the image .

    for (int i = 0; i < SIZE; i ++)
    {

        // Then I loop in every column in the image .

        for (int j = 0; j < SIZE; j ++)
        {

            // I assign each pixel by 255 to make it white .

            result[i][j] = 255 ;

        }
    }

    cout << "\nEnter the Number which you want to Shrink the Image by \nFor Example [Enter (1 / 9) or (1 / 7) and So on]\n"
            "Important Note the Nominator must be 1 -->" ;

    //Here I ask the user to input the value of shrink .

    string str ;

    cin.ignore() ;

    getline(cin, str) ;

    // This rule of while to check if the input correct or no .

    while (true)
    {

        // Here I call rational_option Function to check if the input numbers or not .

        if (rational_option(str))
        {

            // Here I call extract_denominator Function to get the denominator .

            int denominator = extract_denominator(str) ;

            // Then I loop in each pixel in the rows , but I increment i by the value of denominator .

            for (int i = 0; i < SIZE; i += denominator)
            {

                // Then I loop in each pixel in the rows , but I increment i by the value of denominator .

                for (int j = 0; j < SIZE; j += denominator)
                {

                    // Then I assign change the place of the pixel in the new image .

                    // By division the i and j by the denominator .

                    result[i / denominator][j / denominator] = image_1[i][j] ;

                }
            }

            break ;

        }

            // Here if the user input wrong .

        else
        {

            // So I ask the user to input again .

            cout << "\nPlease Enter a number :(\nTry again \n-->" ;

            getline(cin, str) ;

        }
    }
}


//_________________________________________

// Mirror Filter .

void mirror()
{
    //Here i declare an integer called mirror_num .

    int mirror_num ;

    while(true)
    {
        cout << "Enter numbers from 1 to 4 for the part that you want to mirror it\n"
                "1 - mirror 1/2 upper -->\n2 - mirror 1/2 lower -->\n3 - mirror 1/2 right -->\n"
                "4 - mirror 1/2 left -->\n-->" ;

        //Here i take input mirror_num .

        cin >> mirror_num;

        // Check if the mirror_num in the range of 1 to 4.

        if(mirror_num == 1 ||mirror_num == 2 || mirror_num == 3 || mirror_num == 4)
        {
            //if that true break from the loop.

            break;
        }

        else
        {
            //if it false tells the that invalid input and allow to him to enter the input again .

            cout<<"invalid input..."<<endl;

        }
    }

    //if the mirror_num input is equal to 1 .

    if(mirror_num == 1)
    {
        //Here I make for to loop on the half upper of the image .

        for (int i = 0; i < 128 ; ++i)
        {

            for (int j = 0; j < SIZE; j++)

            {

                //Here I put the half upper of the image in the image call result .

                result[i][j] = image_1[i][j];

            }

            //Here I make for to loop on the  half lower of the image .

            for (int i = 128; i < SIZE ; ++i)
            {

                for (int j = 0; j < SIZE; ++j)
                {

                    //I flip the Image Vertical on the  half lower of the image .

                    result [i][j] = image_1[SIZE - i][j - SIZE];

                }
            }
        }
    }

    //if the mirror_num input is equal to 2 .

    else if (mirror_num == 2)
    {
        //Here I make for to loop on the half  lower of the image .

        for (int i = 128; i < SIZE ; ++i)
        {

            for (int j = 0; j < SIZE; ++j)
            {

                //Here I put the half lower of the image in the image call result .

                result[i][j] = image_1[i][j];

            }
        }

        //Here I make for to loop on the  half upper of the image .

        for (int i = 0; i < 128 ; ++i)
        {

            for (int j = 0; j < SIZE; ++j)
            {

                //I flip the Image Vertical on the  half upper of the image .

                result[i][j] = image_1[SIZE - i][j - SIZE];

            }
        }
    }

    //if the mirror_num input is equal to 3 .

    else if(mirror_num == 3)
    {
        //Here I make for to loop on the left half of the image .

        for (int i = 0; i < SIZE ; ++i)
        {

            for (int j = 0; j < SIZE/2; j++)
            {

                //Here I put the right half of the image in the image call result .

                result[i][j] = image_1[i][128 + j];

                result[i][j + 128] = result[i][j];

            }

            //Here I make for to loop on the left half of the image .

            for (int i = 0; i < SIZE ; ++i)
            {

                for (int j = 0; j < 128; ++j)
                {

                    //I flip the left half of the image  Horizontal .

                    result[i][j] = result[i][SIZE - j];

                }
            }
        }
    }

    //if the mirror_num input is equal to 4 .

    else if(mirror_num == 4)
    {
        //Here I make for to loop on the left half of the image .

        for (int i = 0; i < SIZE ; ++i)
        {

            for (int j = 0; j < (SIZE / 2); j++)
            {

                //Here I put the left half of the image in the image call result

                result[i][j] = image_1[i][(SIZE / 2) - j];

                result[i][j+128] = result[i][j];

            }

            //Here I make for to loop on the left half of the image .

            for (int i = 0; i <SIZE ; ++i)
            {

                for (int j = 0; j < SIZE/2; j++)
                {

                    //Here I put the left half of the image in the image call result .

                    result[i][j] = image_1[i][j];

                }
            }
        }
    }
}


//_________________________________________

// Shuffle Filter .

void moveQuarter(int idx, int i, int j)
{
    // I declare tem and assign it by j to use it later .

    int temp = j ;

    // If The quarter is order 1 .

    if (idx == 1)
    {

        // Here I fill quarter of result by the first quarter image .

        for (int k = 0; k < SIZE / 2; i++, k++)
        {

            for (int z = 0, j = temp ; z < SIZE / 2; j++, z++)

                result[i][j] = image_1[k][z] ;

        }
    }

    // If The quarter is order 2 .

    else if (idx == 2)
    {

        // Here I fill quarter of result by the Second quarter image .

        for (int k = 0; k < SIZE / 2; i++, k++)
        {

            for (int z = SIZE / 2, j = temp; z < SIZE; j++, z++)

                result[i][j] = image_1[k][z] ;

        }

    }

    // If The quarter is order 3 .

    else if (idx == 3)
    {

        // Here I fill quarter of result by the third quarter image .

        for (int k = SIZE / 2 ; k < SIZE; i++, k++)
        {

            for (int z = 0, j = temp; z < SIZE/2; j++, z++)

                result[i][j] = image_1[k][z] ;
        }

    }

    // If The quarter is order 4 .

    else if (idx == 4)
    {

        for (int k = SIZE / 2; k < SIZE; i++,k++)
        {

            // Here I fill quarter of result by the fourth quarter image .

            for (int z = SIZE/2, j = temp; z < SIZE; j++,z++)

                result[i][j] = image_1[k][z] ;

        }
    }
}


void shuffleImage()
{
    // Here I declare string text .

    string text = " " ;

    // Here I declare some variables to get the order of the quarters .

    int order_1, order_2, order_3, order_4 ;

    cout<<"\nEnter the order of quarters you want\n-->";

    // Here I loop until the user input correct .

    while(!text.empty())
    {

        // Here I use getline to input the order .

        cin.clear() ;

        cin.sync() ;

        getline(cin, text) ;

        // Here I check if text is correct or not and if its length 4 or not .

        if(order_check(text) && text.length() == 4)
        {

            // Here I get each quarter in variable .

            // I subtract the char from 48 to get the integer of it .

            order_1 = int (text[0] - 48) ;

            order_2 = int (text[1] - 48) ;

            order_3 = int (text[2] - 48) ;

            order_4 = int (text[3] - 48) ;

            break ;

        }

        // Here if user don't input correct .

        else
        {

            // I told the user to try again ,and I get the text empty .

            cout << "\nInvalid input :(\nTry again\n-->" ;

            text = '\0' ;
        }
    }

    // Here I call the function four times .

    for (int i = 0; i < 4; ++i)
    {

        // Here if the quarter is first index .

        if (i == 0)

            // So I call moveQuarter Function and pass it the limit of first quarter ant the order of the quarter .

            moveQuarter(order_1, 0, 0);

        // Here if the quarter is second index .

        else if (i == 1)

            // So I call moveQuarter Function and pass it the limit of second quarter ant the number of the quarter .

            moveQuarter(order_2, 0, SIZE / 2);

        // Here if the quarter is third index .

        else if (i == 2)

            // So I call moveQuarter Function and pass it the limit of third quarter ant the number of the quarter .

            moveQuarter(order_3, SIZE / 2, 0);

        // Here if the quarter is fourth index .

        else if (i == 3)

            // So I call moveQuarter Function and pass it the limit of fourth quarter ant the number of the quarter .

            moveQuarter(order_4, SIZE / 2, SIZE / 2);

    }
}


//_________________________________________

// Blur Filter

void blur()
{

    // Here I declare acg variable to calculate the average of the pixels box .

    long long avg = 0;

    // Here for to loop in each row in the image .

    for (int i = 0 ; i < 250 ; i++)
    {

        // Here for to loop in each column in the image .

        for (int j = 0 ; j < 250 ; j++)
        {

            // Here I get the values of all pixels in the 7 * 7 box .

            // Here for to loop in the 7 pixels in each row .

            for (int k = i; k < (i + 7); k++)
            {

                // Here for to loop in the 7 pixels in each column .

                for (int l = j; l < (j + 7); l++)
                {

                    // Here I increment avg by the value of each pixel in the box .

                    avg = avg + image_1[k][l] ;

                }
            }

            // Heer I assign the pixel in the new image by the average of the values in the pixels box (avg / 49) .

            result[i][j] = (avg / 49) ;

            // Then I assign avg by 0 to get the average of the next box .

            avg = 0 ;

        }
    }

    // After blurring I fix the last 10 rows and columns in the image .

    // Here I fix the last 10 rows .

    for (int k = 250 ; k < SIZE ; k++)
    {

        for (int l = 0 ; l < SIZE ; l++)
        {

            // I assign the color of pixel by the color of pixel above it on the same column .

            result[k][l] = result[k - 1][l] ;

        }

    }

    // Here I fix the last 10 rows .

    for (int k = 0 ; k < SIZE ; k++)
    {

        for (int l = 250 ; l < SIZE ; l++)
        {

            // I assign the color of pixel by the color of pixel before it on the same row .

            result[k][l] = result[k][l - 1] ;

        }
    }
}


//_________________________________________

// Do_something .

void do_something()
{

    char str ;

    cout << "\nEnter The Numbers or characters as ...\n\n1 - Black and white\n2 - Invert\n3 - Merge\n4 - Flip\n5 - Rotate"
            "\n6 - Darken and Lighten\n7 - Detect Image Edges\n8 - Enlarge\n9 - Shrink\nA - Mirror 1/2 Image\nB - Shuffle\nC - Blur"
            "\nS - To save the image\n0 - To Exit\n\nPlease Enter The number of process which you want :) \n-->" ;

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

