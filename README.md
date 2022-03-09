# [ICTIS](http://ictis.sfedu.ru/) [Algorithmization and programming](https://teams.microsoft.com/l/team/19%3aO0HH8J1GghHXuUP-oLiJ3dZeS_cCX32opVsbXOaineI1%40thread.tacv2/conversations?groupId=ed397457-b8a1-48e0-af96-00920a873e6a&tenantId=19ba435d-e46c-436a-84f2-1b01e693e480)

<img src="http://ictis.sfedu.ru/wp-content/uploads/2021/01/%D0%BB%D0%BE%D0%B3%D0%BE.jpg" alt='ictis' height="120" />

Sorting algorithms using C++ for course 'Algorithmization and programming'

# Semester II

## Lab #1. Sorting algorithms.

### Target

To learn the most popular sorting strategies, and it's time complexity. Get a comparative graph.

### Instruction

#### 0. Pre-requirements

<img src="https://git-scm.com/images/logo@2x.png" alt="git" height="70"/>
<img src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png" alt="git-hub" height="100"/>

Students should be familiar with  [Git](https://git-scm.com/) and [GitHub](https://github.com/). Please watch at
least [CS50's video](https://youtu.be/NcoBAfJ6l2Q) if you are not aware about [Git](https://git-scm.com/)
and [GitHub](https://github.com/) at all.

Extra information about Sorting algorithms can be found in [CS50 lecture](https://www.youtube.com/watch?v=eMb84U46FLw).

#### 1. Prepare repository.

1. Login to the [GitHub](https://github.com/) with own account. Please [register](https://github.com/signup?ref_cta=Sign+up&ref_loc=header+logged+out&ref_page=%2F&source=header-home)
Account at github.com using your university account if you don't have such yet. Navigate
to [this project](https://github.com/elpilasgsm/sfedu-ictis-ap-sorting) and click ![Fork](imgs/fork-btn.png) in the top right corner. The
central repository will be cloned to your account. Clone your forked repository to your computer.
More about Fork you can read [here](https://docs.github.com/en/get-started/quickstart/fork-a-repo).
2. Clone repository to your local computer. Please be sure that you have [Git client](https://git-scm.com/downloads) installed at your computer. Install SSH key at your local machine and provide public key to the GitHub. See more information about Access Keys [here](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent). There are following ways to clone project:

    - In the shell (terminal) run the following command:
    ```shell
    git clone git@github.com:***/sfedu-ictis-ap-sorting.git
    ```
    - Use CLion and [Get from VCS](https://www.jetbrains.com/help/idea/set-up-a-git-repository.html).
    - Use [Git For Windows](https://gitforwindows.org/) 

#### 2. Coding

In your forked project in the file [main.cpp](main.cpp#L87) please implement methods market with

```//TODO```

There is also

```//PUT YOUR CODE HERE```

placeholder in the code. You should write code only in these places. If required you can add more ```#include``` to the
file, but the existed are enough to complete the task.

There are 9 places where you should put the code.

#### 3. Validate code

Push your code to the remote repository (origin). The following approaches can be used:

   - In the shell (terminal) run the following command:

```shell
    git commit -am "My code"
    git push 
```
   - In CLion  click 'Ctrl' + 'K', fill the commit description, choose changed files and click 'Commit' button. 
After click 'Ctrl' + 'Shift' + 'K' and click 'Push' button.

Your code will be uploaded to the remote server where automatic tests will be run. 
You can find the results of the performed tests at the ![actions](./imgs/actions.png) page. If the latest workflow in 'green'
than your code passed all tests and lab is done properly, otherwise you should change the code. 

#### 4. Collect Results
 
Click at the latest 'green' workflow at the 'Actions' page. Scroll down to the 'Artifacts' group. In the 'Artifacts' group
you will find 'execution-results' package (clickable). Click it to retrieve the results. The zip file contains 3 csv files with
execution time and the png file with the graph that you should include to the Lab report. 