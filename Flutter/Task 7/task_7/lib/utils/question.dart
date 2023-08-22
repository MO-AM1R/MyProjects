// ignore_for_file: public_member_api_docs, sort_constructors_first
class Question {
  String questionText;
  bool answer;

  Question({
    required this.questionText,
    required this.answer,
  });

  bool getAnswer() {
    return answer;
  }

  String getQuestionText() {
    return questionText;
  }
}
