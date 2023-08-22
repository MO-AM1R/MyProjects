import 'package:flutter/material.dart';
import 'package:task_7/utils/question_album.dart';
import '../Widgets/custom_elevated_button.dart';

class QuizApp extends StatefulWidget {
  const QuizApp({super.key});

  @override
  State<QuizApp> createState() => _QuizAppState();
}

class _QuizAppState extends State<QuizApp> {
  QuestionAlbum questionAlbum = QuestionAlbum();
  int score = 0;
  bool visibleState = true;

  @override
  Widget build(BuildContext context) {
    return Column(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
      Visibility(
        visible: visibleState,
        child: ListTile(
          trailing: const Icon(
            Icons.question_mark,
            size: 25,
            color: Colors.black,
          ),
          title: Text(
            questionAlbum.getNextQuestion().getQuestionText(),
            style: const TextStyle(
                fontSize: 30,
                fontStyle: FontStyle.italic,
                fontWeight: FontWeight.bold),
          ),
        ),
      ),
      Visibility(
        visible: visibleState,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            CustomElevatedButton(
              backGroundColor: const Color.fromARGB(255, 0, 47, 255),
              icon: Icons.check,
              label: 'True',
              textAndIconColor: Colors.white,
              onClick: () {
                setState(() {});
                if (!questionAlbum.checkIfExitQuestion()) {
                  visibleState = !visibleState;
                  if (!questionAlbum.getNextQuestion().getAnswer()) {
                    ++score;
                  }
                  return;
                }
                if (questionAlbum.getNextQuestion().getAnswer()) {
                  ++score;
                }
                questionAlbum.incrementIndex();
              },
            ),
            CustomElevatedButton(
              backGroundColor: Colors.red,
              icon: Icons.close,
              label: 'False',
              textAndIconColor: Colors.white,
              onClick: () {
                setState(() {});
                if (!questionAlbum.checkIfExitQuestion()) {
                  visibleState = !visibleState;
                  if (!questionAlbum.getNextQuestion().getAnswer()) {
                    ++score;
                  }
                  return;
                }
                if (!questionAlbum.getNextQuestion().getAnswer()) {
                  ++score;
                }
                questionAlbum.incrementIndex();
              },
            ),
          ],
        ),
      ),
      Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Text(
            'Your Score ➜ $score',
            style: const TextStyle(fontSize: 30, fontWeight: FontWeight.bold),
          )
        ],
      )
    ]);
  }
}
