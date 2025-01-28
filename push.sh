#!/bin/bash

# Ensure the script stops if any command fails
set -e

# Prompt for commit messages
read -p "Enter a commit message for the submodules: " submodule_msg
read -p "Enter a commit message for the parent repository: " parent_msg

# Push changes in each submodule
echo "Pushing changes in submodules..."
git submodule foreach --recursive "
  echo \"Entering submodule: \$name\"

  # Check if the submodule is initialized
  if [ \"\$(git rev-parse --is-inside-work-tree 2>/dev/null)\" != \"true\" ]; then
    echo \"Submodule \$name is not initialized. Initializing...\"
    git submodule update --init
  fi
  
  # Check if the submodule is in a detached HEAD state
  branch=\$(git symbolic-ref --short HEAD || echo \"detached\")
  if [ \"\$branch\" = \"detached\" ]; then
    echo \"Submodule \$name is in a detached HEAD state. Attempting to fix...\"
    git checkout main || echo \"Branch 'main' does not exist in \$name. Please check manually.\"
  fi

  # Stage and commit any changes in the submodule (if any)
  git add .
  git commit -m \"$submodule_msg\" || echo \"No changes to commit in \$name.\"

  # Push the changes to the submodule's branch
  if [ \"\$branch\" != \"detached\" ]; then
    echo \"Pushing changes for branch \$branch in submodule: \$name...\"
    git push origin \$branch
  fi
"

# Update the parent repository to track the latest submodule references
echo "Pushing changes in the parent repository..."
git add .
git commit -m "$parent_msg" || echo "No changes to commit in parent repository."
git push

echo "All changes in submodules and the parent repository have been pushed!"
