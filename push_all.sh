#!/bin/bash

# Ensure the script stops if any command fails
set -e

# Prompt for a commit message
read -p "Enter a commit message for the submodules: " submodule_msg
read -p "Enter a commit message for the parent repository: " parent_msg

# Push changes in each submodule
echo "Pushing changes in submodules..."
git submodule foreach --recursive '
  echo "Entering submodule: $name"
  branch=$(git symbolic-ref --short HEAD || echo "detached")
  if [ "$branch" = "detached" ]; then
    echo "Submodule $name is in a detached HEAD state. Attempting to fix..."
    git checkout main
    git pull origin main
  fi
  git add .
  git commit -m "'"$submodule_msg"'" || echo "No changes to commit in $name."
  git push origin $(git symbolic-ref --short HEAD)
'

# Go back to the root of the parent repository
echo "Pushing changes in parent repository..."
cd "$(git rev-parse --show-toplevel)"
git add .
git commit -m "$parent_msg" || echo "No changes to commit in parent repository."
git push

echo "All changes pushed successfully!"
