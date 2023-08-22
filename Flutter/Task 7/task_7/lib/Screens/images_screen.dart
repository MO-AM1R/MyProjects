import 'package:flutter/material.dart';

class ImageScreen extends StatelessWidget {
  const ImageScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              SizedBox(
                width: 190,
                height: 300,
                child: Column(
                  children: [
                    Image.asset(
                      'assets/1.jpg',
                    ),
                    const Text(
                      'Iron Man',
                      style:
                          TextStyle(fontWeight: FontWeight.bold, fontSize: 25),
                    )
                  ],
                ),
              ),
              SizedBox(
                width: 190,
                height: 300,
                child: Column(
                  children: [
                    Image.asset(
                      'assets/2.jpg',
                    ),
                    const Text(
                      'Spider Man',
                      style:
                          TextStyle(fontWeight: FontWeight.bold, fontSize: 25),
                    )
                  ],
                ),
              ),
            ],
          ),
          const Text(
            '↪ Marvel Charachters',
            style: TextStyle(fontWeight: FontWeight.bold, fontSize: 30),
          ),
        ],
      ),
    );
  }
}
