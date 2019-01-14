# Introduction to Machine learning

- Machine learning has been used at least for a long time
  - best known case: Optical character recognition (OCR) for scanners

- Turning point in 2006 in a paper by G. Hinton showing a deep neural network recognizing hand-written digits with more than 98% accuracy

- Great advance in last 10 years and ML now used i many, if not all, commercial, industrial, and scientific areas

- Machine Learning has been used in High Energy Physics for past 20 years
  - first examples were neural network for classification task
     - separation of pions and kaons and more in general for particle identification

  - ML was critical for discovery of the Higgs boson
    - neural networks and boosted decision trees used for electron, muon, photon, and jet identification

## Resources
- One of my favorite books on this topic is
[Hands-On Machine Learning with Scikit-Learn and TensorFlow](http://shop.oreilly.com/product/0636920052289.do) by Aurélien Géron
  -  I will be using examples and material from this book i these last 2 lectures.

[<img src="https://covers.oreillystatic.com/images/0636920052289/lrg.jpg" width=200>](http://shop.oreilly.com/product/0636920052289.do)

- All code and examples of this book are available as jupyter notebooks on github at [https://github.com/ageron/handson-ml](https://github.com/ageron/handson-ml)

- This very nice [visual introduction to machine learning](http://www.r2d3.us/visual-intro-to-machine-learning-part-1/) can help you understand quickly some of the basic concepts and language in machine learning

- I also recommend the [course on machine learning on coursera](https://www.coursera.org/learn/machine-learning)



## What is machine learning?
- programming a algorithms (computer, machines, devices, programs) to learn from data

- A more general definition by Arthur Samuel in 1959: Machine Learning is the field of study that gives computers the ability to learn without being explicitly programmed

- examples in real life
  - SPAM filter: perhaps first and best known example of ML
  - face recognition in your picture application
    - clustering similar faces as one person
  - recognition of objects in pictures
    - search by image on Google and Amazon
  - speech recognition
    - virtual assistants responding to voice commands
  - song suggestion on your music streaming service
  - next TV show or movie to watch on video streaming
  - advertisement on social networks and e-commerce sites

- examples in high energy Physics
  - identification  of electrons, muons and kaons from charged tracks in a detector
  - classification of a photon as very good (pure or tight ID) or poor (Loose ID higher probability of not being a real photon)
  - separation of photons from hadronic jets
  - identification of hadronic jets originating from b and c quarks and those from light u, d, s quarks
  - estimation of energy of jets from detector measurements
    - fraction of electromagnetic and hadronic energy
    - geometric shape of jets
  - estimation of energy of photons from detector measurements
    - distribution and shape of energy deposit in electromagnetic calorimeter

- We note that there are 2 types of tasks being addressed by ML
  1. **Classification**: a discrete output (called also labels or categories) based on arbitrary number of input information
    - SPAM categories or suggested folder for emails
    - b-jet vs c-jet vs light-flavor jet
  1. **Regression**: a continuous output based on input
    - selling price for an apartment in Rome based on location, floor, exposure, traffic, noise, elevator, etc.
    - estimate of energy of a photon based on detector information

A technical or engineering oriented definition of Machine Learning by Tom Mitchel, 1997:
*A computer program is said to learn from experience E with respect to some task T and some performance P, if its performance on T, as measured by P, improves by experience E*

Example: SPAM filter
    - task: filtering SPAM
    - experience: good and bad emails as flagged by users
    - performance:  fraction of correctly filtered emails (accuracy)

The algorithm is **trained** on a sample of emails selected by users as good or bad. We call these emails the **training sample**.

The algorithm learns to recognise bad emails by (for example) counting the number of words in common between an incoming email (no label) and bad emails (already flagged).

The algorithm then runs on a  **test sample** to see its success rate or accuracy.

Example: photon identification
- task: separate photons from hadronic jets
- experience: simulated MC  samples of photons and jets. Or very pure samples selected i data by user.
- performance:  fraction of correctly identified photons, or fraction of wrongly identified jets
