import 'package:flutter/material.dart';
import 'package:task_7/Screens/counter_screen.dart';
import 'package:task_7/Screens/images_screen.dart';
import 'package:task_7/Screens/quiz_app.dart';
import 'package:task_7/Screens/welcome_screen.dart';

late String myEmail;

List<Widget> screens = [
  const CounterScreen(),
  const ImageScreen(),
  const QuizApp(),
  const WelcomeScreen()
];
