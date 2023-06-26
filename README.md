# LiteLoaderBDS C++ Plugin Template

The template repository for LiteLoaderBDS C++ plugin development.

## Usage

* Write and build your plugin

  Please refer to [LiteLoaderBDS C++ Plugin Development Documentation](https://cpp.docs.litebds.com/en/) or [LiteLoaderBDS C++ 插件开发文档](https://cpp.docs.litebds.com/zh-Hans/).

* Edit README.md and LICENSE

  You ought not to keep the original README.md, for it contains instructions on how to build your own plugin, which might not fit your plugin repository. The README.md of your repository should contain instructions on how to build, install and use your plugin.

  You don't necessarily want your repository to be open sourced under the Unlicense, so please choose your own license in place of the `LICENSE` file.

## For Beta Developers

If you would like to experience the latest features for plugins in beta versions of LiteLoaderBDS, you can switch the branch of the SDK to beta. Run the commands below under the plugin repository:

```sh
git submodule set-branch --branch beta SDK
git submodule update --init --remote
```

## License

This repository is open source under the Unlicense.
Please refer to [the license file](LICENSE) for further information.