import 'package:flutter/material.dart';
import 'package:task_7/Screens/counter_screen.dart';
import 'package:task_7/Screens/images_screen.dart';
import 'package:task_7/Screens/quiz_app.dart';

class TapBarScreen extends StatelessWidget {
  const TapBarScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 3,
      child: Scaffold(
          drawer: const Drawer(),
          appBar: AppBar(
            leading: ElevatedButton(
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color.fromARGB(255, 255, 0, 0),
                side: null,
                elevation: 0,
                foregroundColor: Colors.black,
              ),
              child: const Icon(Icons.arrow_back),
              onPressed: () {
                Navigator.pop(context);
              },
            ),
            bottom: const TabBar(
              tabs: [
                Tab(
                  icon: Icon(
                    Icons.add_box,
                    size: 25,
                  ),
                ),
                Tab(
                  icon: Icon(
                    Icons.image,
                    size: 25,
                  ),
                ),
                Tab(
                  icon: Icon(
                    Icons.quiz,
                    size: 25,
                  ),
                ),
              ],
              labelColor: Colors.black,
            ),
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
          body: const TabBarView(children: [
            CounterScreen(),
            ImageScreen(),
            QuizApp(),
          ])),
    );
  }
}
