import 'package:flutter/material.dart';

class CounterScreen extends StatefulWidget {
  const CounterScreen({super.key});

  @override
  State<CounterScreen> createState() => _MyWidgetState();
}

class _MyWidgetState extends State<CounterScreen> {
  int counter = 0;
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Container(
                  decoration: const BoxDecoration(
                      color: Colors.black,
                      borderRadius: BorderRadius.all(Radius.circular(30))),
                  child: IconButton(
                      onPressed: () {
                        ++counter;
                        setState(() {});
                      },
                      icon: const Icon(
                        Icons.add,
                        color: Colors.white,
                      ))),
              Text(
                '$counter',
                style:
                    const TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
              ),
              Container(
                  decoration: const BoxDecoration(
                      color: Colors.black,
                      borderRadius: BorderRadius.all(Radius.circular(30))),
                  child: IconButton(
                      onPressed: () {
                        --counter;
                        setState(() {});
                      },
                      icon: const Icon(
                        Icons.remove,
                        color: Colors.white,
                      ))),
            ],
          ),
          Container(
            alignment: Alignment.bottomCenter,
            margin: const EdgeInsets.only(top: 30),
            child: Row(mainAxisAlignment: MainAxisAlignment.center, children: [
              FloatingActionButton(
                onPressed: () {
                  counter = 0;
                  setState(() {});
                },
                backgroundColor: Colors.black,
                child: const Icon(
                  Icons.refresh,
                  color: Colors.white,
                ),
              ),
            ]),
          )
        ],
      ),
    );
  }
}
