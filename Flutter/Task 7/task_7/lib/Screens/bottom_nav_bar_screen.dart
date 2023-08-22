import 'package:flutter/material.dart';
import 'package:task_7/Constants/constants.dart';

class BottomNavBarScreen extends StatefulWidget {
  const BottomNavBarScreen({super.key});

  @override
  State<BottomNavBarScreen> createState() => _BottomNavBarScreenState();
}

class _BottomNavBarScreenState extends State<BottomNavBarScreen> {
  int ind = 0;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        home: Scaffold(
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
        backgroundColor: const Color.fromARGB(255, 255, 0, 0),
        title: const Text(
          'Flutter Task',
          style: TextStyle(
              color: Colors.black, fontSize: 30, fontWeight: FontWeight.bold),
        ),
        centerTitle: true,
      ),
      body: screens[ind],
      bottomNavigationBar: BottomNavigationBar(
        selectedIconTheme: const IconThemeData(color: Colors.black),
        unselectedIconTheme: const IconThemeData(color: Colors.grey),
        type: BottomNavigationBarType.shifting,
        selectedItemColor: Colors.black,
        onTap: (value) {
          setState(() {
            ind = value;
          });
        },
        currentIndex: ind,
        items: const [
          BottomNavigationBarItem(
              icon: Icon(Icons.add_box), label: 'Counter App'),
          BottomNavigationBarItem(icon: Icon(Icons.image), label: 'Images App'),
          BottomNavigationBarItem(icon: Icon(Icons.quiz), label: 'Quiz App'),
        ],
      ),
    ));
  }
}
