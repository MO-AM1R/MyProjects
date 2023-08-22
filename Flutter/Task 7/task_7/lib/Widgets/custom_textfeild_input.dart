import 'package:flutter/material.dart';
import 'package:task_7/Constants/constants.dart';

class CustomTextFeild extends StatefulWidget {
  late final bool obs;
  late final String? label;
  late final String? hintText;
  late final Icon suffix;
  late final Icon? prefix;
  late final TextInputType? keyboardType;

  // ignore: prefer_const_constructors_in_immutables
  CustomTextFeild(
      {super.key,
      required this.label,
      this.obs = false,
      required this.hintText,
      this.suffix = const Icon(Icons.email),
      this.prefix,
      this.keyboardType = TextInputType.emailAddress});

  @override
  State<CustomTextFeild> createState() => _CustomTextFeildState();
}

class _CustomTextFeildState extends State<CustomTextFeild> {
  bool show = true;

  @override
  Widget build(BuildContext context) {
    return TextField(
      obscureText: widget.obs,
      keyboardType: widget.keyboardType,
      onChanged: (value) {
        if (widget.label == 'Email') {
          myEmail = value;
        }
      },
      decoration: InputDecoration(
        border: const OutlineInputBorder(),
        label: Text('${widget.label}'),
        labelStyle: const TextStyle(
            fontWeight: FontWeight.bold, fontSize: 20, color: Colors.indigo),
        hintText: '${widget.hintText}',
        hintStyle: const TextStyle(fontWeight: FontWeight.bold, fontSize: 20),
        suffixIcon: IconButton(
          onPressed: () {
            if (widget.label == 'Password') {
              widget.obs = !widget.obs;
              if (show) {
                widget.suffix = const Icon(Icons.remove_red_eye_outlined);
              } else {
                widget.suffix = const Icon(Icons.remove_red_eye);
              }
              show = !show;

              setState(() {});
            }
          },
          icon: widget.suffix,
        ),
        prefixIcon: widget.prefix,
        suffixIconColor: Colors.indigo,
      ),
    );
  }
}
