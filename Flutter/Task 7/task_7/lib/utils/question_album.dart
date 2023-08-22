import 'package:task_7/utils/question.dart';

class QuestionAlbum {
  List<Question> myQuestion = [
    Question(
        questionText: 'Python is a compiled programming language.',
        answer: false),
    Question(
        questionText:
            'A binary search algorithm requires the list to be sorted beforehand.',
        answer: true),
    Question(questionText: 'HTML is a programming language.', answer: false),
    Question(
        questionText:
            'Recursion is an alternative to iteration in programming.',
        answer: true),
    Question(
        questionText: 'JavaScript can only be run in web browsers.',
        answer: false),
    Question(
        questionText:
            'Object-oriented programming (OOP) focuses on using only functions and procedures.',
        answer: false),
    Question(
        questionText: 'A stack follows the Last-In-First-Out (LIFO) principle.',
        answer: true),
    Question(
        questionText: 'Machine code is directly understandable by humans.',
        answer: false),
  ];
  int index = 0;

  Question getNextQuestion() {
    return myQuestion[index];
  }

  bool checkIfExitQuestion() {
    return index < myQuestion.length - 1;
  }

  void incrementIndex() {
    ++index;
  }
}
