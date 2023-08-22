import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        drawer: const Drawer(),
        appBar: AppBar(
          backgroundColor: const Color.fromARGB(255, 8, 0, 161),
          title: const Text(
            'Task 2 Flutter',
            style: TextStyle(color: Colors.white),
          ),
          actions: const [
            Icon(
              Icons.camera,
              color: Colors.white,
            )
          ],
          centerTitle: true,
          iconTheme: const IconThemeData(color: Colors.white),
        ),
        body: Column(
          children: [
            Container(
              color: Colors.black,
              height: 100,
              child: const SingleChildScrollView(
                scrollDirection: Axis.horizontal,
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: [
                    MyImage(
                      str: 'Hello 1',
                      clr: Colors.blue,
                    ),
                    MyImage(
                      str: 'Hello 2',
                      clr: Colors.deepPurple,
                    ),
                    MyImage(
                      str: 'Hello 3',
                      clr: Colors.red,
                    ),
                    MyImage(
                      str: 'Hello 4',
                      clr: Colors.yellowAccent,
                    ),
                    MyImage(
                      str: 'Hello 5',
                      clr: Colors.lightGreen,
                    ),
                    MyImage(
                      str: 'Hello 6',
                      clr: Colors.grey,
                    ),
                    MyImage(
                      str: 'Hello 7',
                      clr: Colors.deepPurpleAccent,
                    ),
                    MyImage(
                      str: 'Hello 8',
                      clr: Colors.indigo,
                    ),
                  ],
                ),
              ),
            ),
            const MyLabel(
              number: '6565945',
              titleImage: 'Image 1',
            ),
            const MyLabel(
              number: '870012',
              titleImage: 'Image 2',
            ),
            const MyLabel(
              number: '1021314',
              titleImage: 'Image 3',
            ),
            const MyLabel(
              number: '702154',
              titleImage: 'Image 4',
            ),
            const MyLabel(
              number: '587103',
              titleImage: 'Image 5',
            ),
            const Expanded(
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  Column(
                    mainAxisAlignment: MainAxisAlignment.end,
                    children: [Icon(Icons.call), Text('Call')],
                  ),
                  Column(
                    mainAxisAlignment: MainAxisAlignment.end,
                    children: [
                      Icon(Icons.route),
                      Text('route'),
                    ],
                  ),
                  Column(
                    mainAxisAlignment: MainAxisAlignment.end,
                    children: [
                      Icon(Icons.share),
                      Text('share'),
                    ],
                  )
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}

class MyImage extends StatelessWidget {
  final Color clr;
  final String str;

  const MyImage({
    super.key,
    required this.clr,
    required this.str,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
        decoration:
            BoxDecoration(borderRadius: BorderRadius.circular(60), color: clr),
        width: 60,
        height: 60,
        margin: const EdgeInsets.all(10),
        child: Center(
          child: Text(
            str,
            style: const TextStyle(color: Colors.white),
          ),
        ));
  }
}

class MyLabel extends StatelessWidget {
  final String number;
  final String titleImage;

  const MyLabel({
    super.key,
    required this.number,
    required this.titleImage,
  });

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {},
      child: SizedBox(
        width: double.infinity,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Row(children: [
              const MyImage(clr: Color.fromARGB(255, 162, 18, 7), str: 'Name'),
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(number),
                  const SizedBox(
                    height: 5,
                  ),
                  Text(titleImage),
                ],
              ),
            ]),
            const Padding(
              padding: EdgeInsets.only(right: 15),
              child: Icon(Icons.arrow_forward),
            )
          ],
        ),
      ),
    );
  }
}
