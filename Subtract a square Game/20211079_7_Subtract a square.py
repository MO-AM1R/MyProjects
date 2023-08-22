# Name : Mohamed Amir Mohamed Abdullah .
# ID : 20211079 .
# The Game Number : 5 --> Subtract Coins game [ GUI ] by python .
# Idea of the Game : There are two players each player can decrease number of coins ( 100 )
# But he must Enter only Square Number and so on until The last player decrease the last number coins won ! .

from tkinter import *
from tkinter import messagebox

coins = 100
player = True

window_2 = Tk()
window_2.geometry('1920x1707')
window_2.title('Subtract Coins')
window_2.iconbitmap('Icon Coins.ico')
bg = PhotoImage(file='Background2.png.')
background = Label(window_2, image=bg).place(x=0, y=0)


def win():

    if coins == 0 and player:

        messagebox.showinfo("Subtract", "Player 1 won ! \nThe game is over :) ")
        exit()

    elif coins == 0 and not player:

        messagebox.showinfo("Subtract", "Player 2 won ! \nThe game is over :) ")
        exit()


def disable_button_player1():

    button_1.config(state=DISABLED)
    button_2.config(state=DISABLED)
    button_3.config(state=DISABLED)
    button_4.config(state=DISABLED)
    button_5.config(state=DISABLED)
    button_6.config(state=DISABLED)
    button_7.config(state=DISABLED)


def active_button_player1():

    button_1.config(state=NORMAL)
    button_2.config(state=NORMAL)
    button_3.config(state=NORMAL)
    button_4.config(state=NORMAL)
    button_5.config(state=NORMAL)
    button_6.config(state=NORMAL)
    button_7.config(state=NORMAL)


def disable_button_player2():

    button_1_2.config(state=DISABLED)
    button_2_2.config(state=DISABLED)
    button_3_2.config(state=DISABLED)
    button_4_2.config(state=DISABLED)
    button_5_2.config(state=DISABLED)
    button_6_2.config(state=DISABLED)
    button_7_2.config(state=DISABLED)


def active_button_player2():

    button_1_2.config(state=NORMAL)
    button_2_2.config(state=NORMAL)
    button_3_2.config(state=NORMAL)
    button_4_2.config(state=NORMAL)
    button_5_2.config(state=NORMAL)
    button_6_2.config(state=NORMAL)
    button_7_2.config(state=NORMAL)


def subtract(b):

    global coins, player

    if (b['text'] == '1') and player:

        if coins - 1 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 1
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '4') and player:

        if coins - 4 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 4
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '9') and player:

        if coins - 9 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 9
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '16') and player:

        if coins - 16 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 16
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '25') and player:

        if coins - 25 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 25
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '36') and player:

        if coins - 36 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 36
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '49') and player:

        if coins - 49 < 0:

            messagebox.showerror("Subtract", "incorrect process")

        else:

            coins -= 49
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player1()
            active_button_player2()
            win()
            player = False

    elif (b['text'] == '1') and not player:

        if coins - 1 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 1
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True

    elif (b['text'] == '4') and not player:

        if coins - 4 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 4
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True

    elif (b['text'] == '9') and not player:

        if coins - 9 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 9
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True

    elif (b['text'] == '16') and not player:

        if coins - 16 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 16
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True

    elif (b['text'] == '25') and not player:

        if coins - 25 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 25
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True

    elif (b['text'] == '36') and not player:

        if coins - 36 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 36
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True

    elif (b['text'] == '49') and not player:

        if coins - 49 < 0:

            messagebox.showerror("Subtract", "Incorrect process")

        else:

            coins -= 49
            label.config(text="Coins    Number    =     " + str(coins))
            label_2.config(text="Coins    Number    =     " + str(coins))

            disable_button_player2()
            active_button_player1()
            win()
            player = True


welcome = Label(window_2, text="Welcome   to   Game    :) ", fg='Black',
                font=('Script MT Bold', 40, 'bold'), bg='#FF0000')

welcome.place(x=5, y=5)

label = Label(window_2, width=27, height=3, text='Coins    Number    =     100', fg='White',
              font=('Script MT Bold', 20, 'bold'), bd=4, bg='Black')

label.place(x=220, y=200)

player_1 = Label(window_2, width=27, height=3, text='   Player    1    ', fg='White',
                 font=('Script MT Bold', 20, 'bold'), bd=4, bg='Black')

player_1.place(x=220, y=350)

player_2 = Label(window_2, width=27, height=3, text='   Player    2    ', fg='White',
                 font=('Script MT Bold', 20, 'bold'), bd=4, bg='Red')

player_2.place(x=1235, y=350)

label_2 = Label(window_2, width=27, height=3, text='Coins    Number    =     100', fg='White',
                font=('Script MT Bold', 20, 'bold'), bd=4, bg='Red')

label_2.place(x=1235, y=200)

button_1 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_1), text="1")

button_1.place(x=100, y=500)

button_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_2), text="4")

button_2.place(x=380, y=500)

button_3 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_3), text="9")

button_3.place(x=680, y=500)

button_4 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_4), text="16")

button_4.place(x=100, y=650)

button_5 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_5), text="25")

button_5.place(x=380, y=650)

button_6 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_6), text="36")

button_6.place(x=680, y=650)

button_7 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Black',
                  command=lambda: subtract(button_7), text="49")

button_7.place(x=380, y=800)

button_1_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_1_2), text="1")

button_1_2.place(x=1120, y=500)

button_2_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_2_2), text="4")

button_2_2.place(x=1400, y=500)

button_3_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_3_2), text="9")

button_3_2.place(x=1700, y=500)
button_4_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_4_2), text="16")

button_4_2.place(x=1120, y=650)

button_5_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_5_2), text="25")

button_5_2.place(x=1400, y=650)

button_6_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_6_2), text="36")

button_6_2.place(x=1700, y=650)

button_7_2 = Button(window_2, width=5, bd=4, fg='White', font=('Times', 20, 'bold'), bg='Red',
                    command=lambda: subtract(button_7_2), text="49")

button_7_2.place(x=1400, y=800)

disable_button_player2()

window_2.mainloop()
