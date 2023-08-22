import 'package:flutter/material.dart';
import 'package:task_7/Constants/constants.dart';
import 'package:task_7/Widgets/custom_elevated_button.dart';
import 'package:task_7/Widgets/custom_textfeild_input.dart';

class LoginScreen extends StatelessWidget {
  const LoginScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'Flutter Task',
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
          useMaterial3: true,
        ),
        home: Scaffold(
          drawer: const Drawer(),
          appBar: AppBar(
            backgroundColor: const Color.fromARGB(255, 255, 0, 0),
            title: const Text(
              'Flutter Task',
              style: TextStyle(
                  color: Colors.black,
                  fontSize: 30,
                  fontWeight: FontWeight.bold),
            ),
            centerTitle: true,
          ),
          body: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Image.asset(
                    'assets/1.jpg',
                    width: 200,
                    height: 130,
                  ),
                ],
              ),
              CustomTextFeild(
                hintText: 'Write your Email',
                label: 'Email',
                suffix: const Icon(Icons.email),
              ),
              CustomTextFeild(
                hintText: 'Write your Password',
                label: 'Password',
                prefix: const Icon(Icons.password),
                obs: true,
                suffix: const Icon(Icons.remove_red_eye),
                keyboardType: TextInputType.visiblePassword,
              ),
              CustomElevatedButton(
                  label: 'Login',
                  textAndIconColor: Colors.white,
                  backGroundColor: Colors.indigo,
                  onClick: () {
                    Navigator.pushNamed(context, "Welcome", arguments: {
                      'Email': myEmail,
                      'Name': myEmail.contains('@')
                          ? myEmail.substring(0, myEmail.indexOf('@'))
                          : myEmail
                    });
                  },
                  icon: (Icons.login)),
            ],
          ),
        ));
  }
}
