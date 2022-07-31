pipeline {
    agent { dockerfile {
                filename 'dockerfile'
                       } 
          }
    stages {
        stage('build.sh') {
            steps {
                sh 'build.sh'
            }
        }
    }
}
