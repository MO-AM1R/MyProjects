import 'package:flutter/material.dart';
import 'package:task_7/Widgets/custom_elevated_button.dart';

class WelcomeScreen extends StatelessWidget {
  const WelcomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    var info =
        ModalRoute.of(context)?.settings.arguments as Map<String, String>;

    return MaterialApp(
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
              Row(mainAxisAlignment: MainAxisAlignment.center, children: [
                Text("Hello ↪ ${info['Name']}",
                    style: const TextStyle(
                        fontSize: 20, fontWeight: FontWeight.bold)),
              ]),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Text("Your Email ↪ ${info['Email']}",
                      style: const TextStyle(
                          fontSize: 20, fontWeight: FontWeight.bold)),
                ],
              ),
              SizedBox(
                height: 300,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    CustomElevatedButton(
                        label: 'Bottom Nav Bar',
                        textAndIconColor: Colors.white,
                        backGroundColor: Colors.black,
                        onClick: () {
                          Navigator.pushNamed(context, 'BottomNavBar');
                        },
                        icon: Icons.navigate_next),
                    CustomElevatedButton(
                        label: 'Tap Bar',
                        textAndIconColor: Colors.white,
                        backGroundColor: Colors.black,
                        onClick: () {
                          Navigator.pushNamed(context, 'TapBar');
                        },
                        icon: Icons.navigate_next),
                    CustomElevatedButton(
                        label: 'Drawer',
                        textAndIconColor: Colors.white,
                        backGroundColor: Colors.black,
                        onClick: () {
                          Navigator.pushNamed(context, 'DrawerScreen');
                        },
                        icon: Icons.navigate_next),
                    CustomElevatedButton(
                        label: 'Logout',
                        textAndIconColor: Colors.white,
                        backGroundColor: Colors.black,
                        onClick: () {
                          Navigator.pushNamedAndRemoveUntil(
                              context, '/', (route) => false);
                        },
                        icon: Icons.logout),
                  ],
                ),
              ),
            ],
          )),
    );
  }
}
