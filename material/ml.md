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
Two of my favorite books on this topic are

- [Hands-On Machine Learning with Scikit-Learn and TensorFlow](http://shop.oreilly.com/product/0636920052289.do) by Aurélien Géron
[<img src="https://covers.oreillystatic.com/images/0636920052289/lrg.jpg" width=150>](http://shop.oreilly.com/product/0636920052289.do)
  - All code and examples of this book are available as jupyter notebooks on github at [https://github.com/ageron/handson-ml](https://github.com/ageron/handson-ml)

- [Introduction to Machine Learning with Python](https://www.oreilly.com/library/view/introduction-to-machine/9781449369880/) by Andreas C. Mueller and Sarah Guido
[<img src="https://learning.oreilly.com/library/cover/9781449369880/250w/" width=150>](hhttps://www.oreilly.com/library/view/introduction-to-machine/9781449369880/)
  - All code and examples of this book are available as jupyter notebooks on github at [https://github.com/amueller/introduction_to_ml_with_python](https://github.com/amueller/introduction_to_ml_with_python)



-  I will be using examples and material from this book i these last 2 lectures.


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
- experience:
  - simulated MC  samples of photons and jets (MC based method)
  - very pure samples selected data by user (data driven method)
- performance:  fraction of correctly identified photons, or fraction of wrongly identified jets

## Advantage of machine Learning
Traditional programming technique for an algorithm in these examples consists in
 1. define rules for classification based on concrete examples
     - examples of already known SPAM
     - identified photons in different geometric configurations and energy range
 1. Write algorithm based on patterns found in examples
 1. test program and add rules to increase accuracy
 1. release program for general use

 List of rules in both cases can become very long if you want to make your algorithm robust. You will have many **if** statements and will have to update often the list.
 If list is not updated, algorithm quickly becomes obsolete and useless
   - think about cheap or free virus protection programs not being updated


 In machine learning approach, rules are not hardcoded. Algorithms are __trained__ with data to find patterns and update the algorithm.
   - new SPAM emails identified by training
   - new photon distributions found when a new type of process studied in a new energy range or at a new center-of-mass energy

Maintenance in general easier, and results more accurate and reliable.


### Complex problems
Some problems are intrinsically complex and cannot have a simple rule-based solution,  no matter how long the rule-list
  - speech recognition
    - different environment , rooms, conditions, accents
  - image recognition
    - quality of image, perspective, colors, contrast, lighting
  - b-jet identification
    - jet energy and underlying process, number of simultaneous interactions, energy spectrum, number of hadrons

in all these cases the machine learning approach is pretty much your only viable solution.

## Data language
With *data point* we indicate a collection of information concerning an object, an event, or a measurement that can be fed as input to an algorithm. Each type of information is called an **attribute** and together with its value it is a **feature** of the data point.

   - an email has a subject, sender, recipient, body, number of words
   - an apartment has a surface, location, floor, sun exposure, energy class
   - a picture is made of N pixels each with a value
      - for example in a black-and-white picture the value of each pixel can be from 0 (white) to 255 (black)
   - a photon has energy, shape of energy deposit, associated hadronic energy, number of crystals above threshold, fraction of energy in central crystal    


## Types of machine Learning
- A key element of ML is the training of the algorithm.
- ML techniques can be classified according to
  - amount of supervision during training
  - type of supervision during training

### 1. Supervised learning
Training data sample includes the desired result (label) and is used to teach algorithm good from bad
  - sample of good emails and SPAM emails filtered by humans
     - a good email is really a good email (true positive)
     - a SPAM email is a real SPAM (true negative)
  - simulated sample of photons and hadronic jets
    - sample of proton collisions producing two real photons
    - sample of QCD events producing only hadronic jets

 - simulated sample of photons with

### 2. Unsupervised learning
Training data does not have any labels, e.g.  indicating good and bad emails.
Algorithms determine clusters of data based on their features  
- handy for clustering diverse users and clients of a service
- can help identifying correlation between features and a data and reduce number of features to be used (dimentionality reduction)
  - sun exposure and light in an apartment correlated to number of windows
  - mileage of a used car highly correlated with its age
  - energy of a very high energy photon correlated with number of crystals over noise threshold

###  3. Semisupervised learning
Training uses a mixture of  labelled and unlabeled data.
For example algorithm identifies common clusters of data which are then labeled.
Labled data then used for further training.

Photo hosting services use this technique for face recognition
- unsupervised training finds groups of faces that are similar
- user provides label for each group
  - some groups are for same label and are merged
- algorithm uses labeled groups to further classify pictures


###  4. Reinforcement learning
Used heavily in robotics to learn by itself over time.
- A system observes data from environment with no guidance.
- actions are taken and a score is given
  - for example playing chess or Go or other table games
- system learns from its past action by maximising the score



## Stream of data for learning process

Learning techniques can also be classified based on how they use data for training

### Batch learning
Training done with largest sample available and algorithm cannot learn incrementally.
- requests large amount of data and Computing
- algorithm trained for available data and put in production for use

if new features or new sources of data become available, must restart with new training and prepare a new version to be put in production

While the process can be automated, the needs in terms of CPU, storage, memory, and time requirements can be challenging.

In commercial application this can be redone every week or even everyday at computing center, but not realistic on a smartphone.

#### Example: photon identification algorithm
- each year a different configuration of detector subsystems
- possibly different center-of-mass energy in collisions
- improved detector calibration and alignment
- different number of simultaneous collisions

Each year, or even every few months, must do new training for new data sample recorded
- large samples of simulated events must be produced for training

### Incremental or online Learning
Data fed incrementally for training
- training done on subset of data.
- knowledge learned from data stored, but data can be discarded
  - for example on a device with limited resources like a phone or a rover on Mars
- each learning step is relatively fast

Incremental learning can quickly learn and adapt to new conditions and features.

Biggest challenge is the quality of data. Bad data or biased data can mislead an algorithm and make it ineffective
- broken sensor with incorrect reading of radiation or noise or temperature
- SPAM data labeled as good by mistake
- good data wrongly labeled as SPAM


## Main challenges for machine learning
- Amount of quality of data is the main challenge for machine learning.

- Unlike most humans, algorithms need a lot of data and large samples, and also of very good quality to learn good and bad

### non-representative data
- Feed images in day light to train recognition of an object and then apply algorithm to images at night
  - object boundaries not well defined

- Train photon identification for photons with energy below 20 GeV and then apply them to photons with 200 GeV energy
  - energy profile and depth depends on energy

### Poor-quality data
- Features with large uncertainty (noise) will confuse algorithms
  -  a neat image is always better than a noisy or low-quality image for learning  
- Data samples with missing features can make classification more difficult

In general homogenous and comparable samples with high purity make training more efficient and reduce false positives.

### Irrelevant features
ML algorithms are not black boxes. Often people give a large number of features, many perhaps irrelevant or highly correlated, to an algorithm.
- training requires longer time, more resources
- results can be less reliable because of noise introduced  by irrelevant features

It's always better to start with a well understood (certainly in physics analysis) features to train. Then incrementally add features and evaluate gain in performance (accuracy) compared to complexity (evaluation of systematic uncertainties)

### Over-fitting or under-fitting training data
Training is the critical element of any algorithm. Two common problems can happen due to quality and size of data and/or modeling of the data
- complex model is used with non-adequate training sample. The model is over constrained and does not perform well on actual data

- a very simplistic model is used to model a complex and/or large sample and again cannot describe features of realistic and complete data samples

 ### Test and validation
 It is good practice to  define the following samples when using ML Methods
 - large enough sample of training
   - size depends on complexity of problem and model under study
 - a test sample to apply trained algorithm and study its performance
 - the actual datasample where we intend to use the ML algorithm to identify a signal

 Example: b-tagging algorithm to search for exotic new events at LHC
 - large MC samples or pure samples of b-jets from standard model processes such as p-p collisions produce a pair of top quark-antiquark
 - apply algorithm to identify Z -> bb or Higgs -> bb decays
 - use algorithm to search  for new heavy particles decaying to one or more b quarks


## Example of b-tagging algorithm
An example of machine learning in identification of jets from heavy flavor quarks is described in [this document](http://cms-results.web.cern.ch/cms-results/public-results/publications/BTV-16-002/index.html) using LHC data recorded with the CMS detector.

**Task**: separating hadronic jets from b and c quarks and those from u,d,s quarks and gluons

<img src="img/CMS-BTV-16-002_Figure_001.png" width=500px>

Useful attributes include:
- distance between tracks and the axis of the jet at point of closest approach <br/>
<img src="img/CMS-BTV-16-002_Figure_002.png" width =600px>

- average track multiplicity in jets as a function of their pt and $\eta$<br/>
<img src="img/CMS-BTV-16-002_Figure_004.png" width =600px>

- 3D impact parameter value and its significance. 2D impact parameter for 1st and 2nd most energetic tracks<br/>
<img src="img/CMS-BTV-16-002_Figure_005.png" width =600px>

- distribution of secondary vertex mass and flight distance in 2D<br/>
<img src="img/CMS-BTV-16-002_Figure_006.png" width =600px>

- number of secondary vertices inside a b-jet<br/>
<img src="img/CMS-BTV-16-002_Figure_007-a.png" width =300px>

Distributions are compared between data and MC to make sure results and performance obtained with simulation can be applied to data.

<img src="img/CMS-BTV-16-002_Figure_030.png" width =600px>

**Training data**:

- signal:  simulated sample of pair production of top quarks <br/>
<img src="img/top-production.png" width=200px>

- background: QCD multijet events

**Performance**:
ROC curve for different algorithms using same input data but different ML algorithms compared to traditional likelihood based algorithm JP(jet probability).

<img src="img/CMS-BTV-16-002_Figure_016.png" width=600>


## Exercise with pandas and scikit-learn
Chapter 1 of [Hands-On Machine Learning with Scikit-Learn and TensorFlow](http://shop.oreilly.com/product/0636920052289.do) has a simple example of using scikit-learn and pandas with publicly available data. You can also use the [interactive jupyter notebook](https://github.com/ageron/handson-ml/blob/master/01_the_machine_learning_landscape.ipynb) for chapter 1 with the complete example.

## Exercise: ML with arduino
- program an accelerator module to record movement data on SD card on the board
- collect data in different conditions
  - walking slowly
  - walking fast
  - running
- identify list of attributes to be used by a ML algorithm to distinguish each activity
  - vertical and horizontal acceleration
  - oscillation of average position
  - frequency of oscillation

- use [matplotlib](https://matplotlib.org) for visualization of data

- convert data to use [pandas](http://pandas.pydata.org) [DataFrame](https://pandas.pydata.org/pandas-docs/version/0.23.4/generated/pandas.DataFrame.html) instead of simple NumPy ndarray
- use [scikit-learn](https://scikit-learn.org/stable/) to do classification using for example boosted trees
