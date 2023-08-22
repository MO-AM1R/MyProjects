// ignore_for_file: public_member_api_docs, sort_constructors_first

import 'package:flutter/material.dart';

class CustomElevatedButton extends StatefulWidget {
  final String label;
  final Color textAndIconColor;
  final Color backGroundColor;
  final dynamic onClick;
  final IconData icon;

  const CustomElevatedButton({
    Key? key,
    required this.label,
    required this.textAndIconColor,
    required this.backGroundColor,
    required this.onClick,
    required this.icon,
  }) : super(key: key);

  @override
  State<StatefulWidget> createState() => _CustomElevatedButtonState();
}

class _CustomElevatedButtonState extends State<CustomElevatedButton> {
  @override
  Widget build(BuildContext context) {
    return ElevatedButton.icon(
      style: ButtonStyle(
          backgroundColor: MaterialStatePropertyAll(widget.backGroundColor)),
      onPressed: widget.onClick,
      label: Text(
        widget.label,
        style: TextStyle(
            color: widget.textAndIconColor,
            fontSize: 20,
            fontWeight: FontWeight.bold),
      ),
      icon: Icon(
        widget.icon,
        color: widget.textAndIconColor,
        size: 30,
      ),
    );
  }
}
