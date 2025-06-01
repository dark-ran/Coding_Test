# [Gold II] \(\text{Con}+\cfrac{\text{tin}}{\text{ued}+\cfrac{\text{Frac}}{\text{tions}}}\) - 10386 

[문제 링크](https://www.acmicpc.net/problem/10386) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

사칙연산, 많은 조건 분기, 구현, 수학

### 제출 일자

2025년 6월 1일 12:52:48

### 문제 설명

<p>The (simple) continued fraction representation of a real number r is an expression obtained by an iterative process of representing r as a sum of its integer part and the reciprocal of another number, then writing this other number as the sum of its integer part and another reciprocal, and so on. In other words, a continued fraction representation of r is of the form</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-msub space="4"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mfrac space="3"><mjx-frac type="d"><mjx-num><mjx-nstrut type="d"></mjx-nstrut><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-num><mjx-dbox><mjx-dtable><mjx-line type="d"></mjx-line><mjx-row><mjx-den><mjx-dstrut type="d"></mjx-dstrut><mjx-mrow><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mfrac space="3"><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mrow size="s"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mfrac><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mrow size="s"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.311em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c22EF"></mjx-c></mjx-mo></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>r</mi><mo>=</mo><msub><mi>a</mi><mn>0</mn></msub><mo>+</mo><mfrac><mn>1</mn><mrow><msub><mi>a</mi><mn>1</mn></msub><mo>+</mo><mfrac><mn>1</mn><mrow><msub><mi>a</mi><mn>2</mn></msub><mo>+</mo><mfrac><mn>1</mn><mrow><msub><mi>a</mi><mn>3</mn></msub><mo>+</mo><mo>⋯</mo></mrow></mfrac></mrow></mfrac></mrow></mfrac></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[r = a_0 + \frac{1}{a_1 + \frac{1}{a_2 + \frac{1}{a_3 + \cdots}}}\]</span> </mjx-container></p>

<p>where a<sub>0</sub>, a<sub>1</sub>, a<sub>2</sub>, . . . are integers and a<sub>1</sub>, a<sub>2</sub>, . . . > 0. We call the a<sub>i</sub>-values partial quotients. For example, in the continued fraction representation of 5.4 the partial quotients are a<sub>0</sub> = 5, a<sub>1</sub> = 2, and a<sub>2</sub> = 2. This representation of a real number has several applications in theory and practice.</p>

<p>While irrational numbers like √2 require an infinite set of partial quotients, any rational number can be written as a continued fraction with a unique, finite set of partial quotients (where the last partial quotient is never 1 in order to preserve uniqueness). Given two rational numbers in continued fraction representation, your task is to perform the four elementary arithmetic operations on these numbers and display the result in continued fraction representation.</p>

### 입력 

 <p>Each test case consists of three lines. The first line contains two integers n<sub>1</sub> and n<sub>2</sub>, 1 ≤ n<sub>i</sub> ≤ 9 specifying the number of partial quotients of two rational numbers r<sub>1</sub> and r<sub>2</sub>. The second line contains the partial quotients of r<sub>1</sub> and the third line contains the partial quotients of r<sub>2</sub>. The partial quotients satisfy |a<sub>0</sub>| ≤ 10 and 0 < a<sub>i</sub> ≤ 10, the last partial quotient will never be 1, and r<sub>2</sub> is non-zero. A line containing two 0’s will terminate input.</p>

### 출력 

 <p>For each test case, display the case number followed by the continued fraction representation of r<sub>1</sub>+r<sub>2</sub>, r<sub>1</sub>−r<sub>2</sub>, r<sub>1</sub>×r<sub>2</sub>, and r<sub>1</sub>/r<sub>2</sub> in order, each on a separate line. Use 64-bit integers for all of your calculations (long long in C++ and long in Java).</p>

