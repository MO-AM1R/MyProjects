import 'package:flutter/material.dart';
import 'package:task_7/Screens/counter_screen.dart';
import 'package:task_7/Screens/images_screen.dart';
import 'package:task_7/Screens/quiz_app.dart';

class DrawerScreen extends StatefulWidget {
  const DrawerScreen({super.key});

  @override
  State<DrawerScreen> createState() => _DrawerScreenState();
}

class _DrawerScreenState extends State<DrawerScreen> {
  dynamic curScreen = const Center(
    child: Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Icon(
          Icons.arrow_circle_left_outlined,
          size: 35,
        ),
        SizedBox(
          width: 40,
        ),
        Text(
          'See Drawer',
          style: TextStyle(fontSize: 40, fontWeight: FontWeight.bold),
        ),
      ],
    ),
  );

  void changeScreen(dynamic newScreen) {
    setState(() {
      curScreen = newScreen;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        home: Scaffold(
            drawer: Drawer(
              child: ListView(
                children: [
                  DrawerHeader(child: Image.asset('assets/1.jpg')),
                  ListTile(
                    onTap: () {
                      setState(() {
                        curScreen = const QuizApp();
                      });
                    },
                    leading: const Icon(
                      Icons.quiz,
                      size: 40,
                    ),
                    iconColor: Colors.black,
                    title: const Text(
                      'Quiz',
                      style: TextStyle(
                          color: Colors.black,
                          fontSize: 20,
                          fontWeight: FontWeight.bold),
                    ),
                  ),
                  ListTile(
                    onTap: () {
                      setState(() {
                        curScreen = const CounterScreen();
                      });
                    },
                    leading: const Icon(
                      Icons.add_box,
                      size: 40,
                    ),
                    iconColor: Colors.black,
                    title: const Text(
                      'Counter App',
                      style: TextStyle(
                          color: Colors.black,
                          fontSize: 20,
                          fontWeight: FontWeight.bold),
                    ),
                  ),
                  ListTile(
                    onTap: () {
                      setState(() {
                        curScreen = const ImageScreen();
                      });
                    },
                    leading: const Icon(
                      Icons.image,
                      size: 40,
                    ),
                    iconColor: Colors.black,
                    title: const Text(
                      'Images App',
                      style: TextStyle(
                          color: Colors.black,
                          fontSize: 20,
                          fontWeight: FontWeight.bold),
                    ),
                  ),
                  ListTile(
                    onTap: () {
                      Navigator.pop(context);
                    },
                    leading: const Icon(
                      Icons.exit_to_app,
                      size: 40,
                    ),
                    iconColor: Colors.black,
                    title: const Text(
                      'Welcome',
                      style: TextStyle(
                          color: Colors.black,
                          fontSize: 20,
                          fontWeight: FontWeight.bold),
                    ),
                  ),
                ],
              ),
            ),
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
            body: curScreen));
  }
}
