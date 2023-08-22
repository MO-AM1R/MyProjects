import 'package:flutter/material.dart';
import 'package:task_7/Screens/bottom_nav_bar_screen.dart';
import 'package:task_7/Screens/counter_screen.dart';
import 'package:task_7/Screens/drawer_screen.dart';
import 'package:task_7/Screens/images_screen.dart';
import 'package:task_7/Screens/login_screen.dart';
import 'package:task_7/Screens/quiz_app.dart';
import 'package:task_7/Screens/tab_bar_screen.dart';
import 'package:task_7/Screens/welcome_screen.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(initialRoute: '/', routes: {
      '/': (context) => const LoginScreen(),
      'Welcome': (context) => const WelcomeScreen(),
      'BottomNavBar': (context) => const BottomNavBarScreen(),
      'TapBar': (context) => const TapBarScreen(),
      'DrawerScreen': (context) => const DrawerScreen(),
      'Quiz': (context) => const QuizApp(),
      'CounterApp': (context) => const CounterScreen(),
      'ImagesApp': (context) => const ImageScreen(),
    });
  }
}
